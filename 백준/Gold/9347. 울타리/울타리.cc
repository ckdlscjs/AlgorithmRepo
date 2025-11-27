/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int T, R, C;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int INF = 987654321;
int arr[1'005][1'005], cnts[1'000'005];
int visited[1'005][1'005];
std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> pq;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> T;
    for(int t = 0; t < T; t++)
    {
        std::fill_n(&visited[0][0], 1'005*1'005, INF);
        std::memset(cnts, 0, sizeof(cnts));
        std::cin >> R >> C;
        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++)
            {
                std::cin >> arr[r][c];
                if(r == 0 || c == 0 || r == R-1 || c == C-1)
                {
                    visited[r][c] = arr[r][c];
                    pq.push({visited[r][c], r, c});
                }
            }
        }
        int largeIdx = 0; 
        while(pq.size())
        {
            int cc = std::get<0>(pq.top());
            int cy = std::get<1>(pq.top());
            int cx = std::get<2>(pq.top());
            pq.pop();
            //std::cout << cc << ' ' << cy << ' ' << cx << '\n';
            if(cc > visited[cy][cx]) continue;
            largeIdx = std::max(cc, largeIdx);
            cnts[cc] += arr[cy][cx] ? 0 : 1; 
            for(int dir = 0; dir < 4; dir++)
            {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                if(ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx] <= cc) continue;
                pq.push({cc+arr[ny][nx], ny, nx});
                visited[ny][nx] = cc + arr[ny][nx];
            }
        }
    
        while(largeIdx > 0 && cnts[largeIdx] <= 0)
            largeIdx--;
        std::cout << largeIdx << ' ' << cnts[largeIdx] << '\n';
    }
    return 0;
}
