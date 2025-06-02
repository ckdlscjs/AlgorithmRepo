/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
using pii = std::pair<int, int>;
using ti3 = std::tuple<int, int, int>;
using ti5 = std::tuple<int, int, int, int, int>;
using ti6 = std::tuple<int, int, int, int, int, int>;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int N, M, K, res;
ti6 boards[52][52];
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
