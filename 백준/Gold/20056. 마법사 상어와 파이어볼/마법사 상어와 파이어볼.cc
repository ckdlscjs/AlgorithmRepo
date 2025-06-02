/*
1.접근방식:
시뮬레이션문제, 있는그대로 조건에 맞춰 구현하면 되나 최적화를위해 여러방법을 사용해보았다, map의 key로 pair를 두고 체크해봤는데 이보다 더 빠른방법이
있을거같아 여러 방법중 y,x,m,s,d,cnt를 자료형으로하는 2차원 배열을 두고 이를 사용한다, 특이사항으론 s를 dy,dx로 계산할때 역수부분을 계산하기위해 양수로 
바꾸고 모듈러 연산후 N에서 빼주는 형태로 뒤쪽의 위치를맞춘다, 이후다시모듈러연산한다(그냥넘어갈경우계산도해야함)
이후 n^2을 수행하면서 조건에맞는대로 시뮬레이션한다, cnt가 <=0이라면 초기화등 기타 조건문과정이 필요없으므로 이부분도최적화한다

2.시간복잡도:
O(K*N^2)
*/
#include <bits/stdc++.h>
using pii = std::pair<int, int>;
using ti5 = std::tuple<int, int, int, int, int>;
using ti6 = std::tuple<int, int, int, int, int, int>;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int N, M, K, res;
ti6 boards[50][50];
std::queue<ti5> q;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    for(int i = 0; i < M; i++)
    {
        int r, c, m, s, d;
        std::cin >> r >> c >> m >> s >> d;
        q.push({r-1, c-1, m, s, d});
    }
    for(int k = 0; k < K; k++)
    {
        res = 0;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            int y = std::get<0>(cur);
            int x = std::get<1>(cur);
            int m = std::get<2>(cur);
            int s = std::get<3>(cur);
            int d = std::get<4>(cur);
            int ny = y + dy[d] * s;
            if(ny < 0) ny = N - (-ny % N);
            ny %= N;
            int nx = x + dx[d] * s;
            if(nx < 0) nx = N - (-nx % N);
            nx %= N;
            std::get<0>(boards[ny][nx]) += (d % 2 ? 1 : 0);     //odd
            std::get<1>(boards[ny][nx]) += (d % 2 ? 0 : 1);     //even
            std::get<2>(boards[ny][nx]) += m;                   //m
            std::get<3>(boards[ny][nx]) += s;                   //s
            std::get<4>(boards[ny][nx]) = d;                    //d
            std::get<5>(boards[ny][nx]) += 1;                   //cnt
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(std::get<5>(boards[i][j]) <= 0) continue;
                int odd = std::get<0>(boards[i][j]);      //odd
                int even = std::get<1>(boards[i][j]);     //even
                int m = std::get<2>(boards[i][j]);        //m
                int s = std::get<3>(boards[i][j]);        //s
                int d = std::get<4>(boards[i][j]);        //d
                int cnt = std::get<5>(boards[i][j]);      //cnt
                std::get<0>(boards[i][j]) = 0;
                std::get<1>(boards[i][j]) = 0;
                std::get<2>(boards[i][j]) = 0;
                std::get<3>(boards[i][j]) = 0;
                std::get<4>(boards[i][j]) = 0;
                std::get<5>(boards[i][j]) = 0;
                if(cnt == 1)
                {
                    q.push({i, j, m, s, d});
                    res += m;
                }
                else if(cnt > 1)
                {
                    m /= 5;
                    s /= cnt;
                    if(m <= 0) continue;
                    if(odd >= cnt || even >= cnt)
                    {
                        q.push({i, j, m, s, 0});
                        q.push({i, j, m, s, 2});
                        q.push({i, j, m, s, 4});
                        q.push({i, j, m, s, 6});
                    }
                    else
                    {
                        q.push({i, j, m, s, 1}); 
                        q.push({i, j, m, s, 3});
                        q.push({i, j, m, s, 5});
                        q.push({i, j, m, s, 7});
                    }
                    res += m*4;
                }
            }
        }
    }
    std::cout << res;
    return 0;
}
