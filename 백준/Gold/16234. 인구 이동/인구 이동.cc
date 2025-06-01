/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, L, R, A[52][52], areas[52][52], res;
std::pair<int, int> dfs(const int area, int y, int x)
{
    areas[y][x] = area;
    std::pair<int, int> ret(1, A[y][x]);
    for(int dir = 0; dir < 4; dir++)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N || areas[ny][nx]) continue;
        int diff = std::abs(A[ny][nx] - A[y][x]);
        if(L <= diff && diff <= R)
        {
            auto temp = dfs(area, ny, nx);
            ret.first += temp.first;
            ret.second += temp.second;
        }
    }
    return ret;
}
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> L >> R;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            std::cin >> A[i][j];
    while(1)
    {
        int area = 1;
        int rets[N*N + 1];
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(areas[i][j] == 0)
                {
                    auto ret = dfs(area, i, j);
                    rets[area++] = ret.second / ret.first;
                }
                A[i][j] = rets[areas[i][j]];
            }
        }
        if(area > N*N) break;
        std::memset(areas, 0, sizeof(areas));
        res++;
    }
    std::cout << res;
    
    return 0;
}
