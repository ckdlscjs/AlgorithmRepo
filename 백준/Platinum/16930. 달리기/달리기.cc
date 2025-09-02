/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
const int INF = 1e6 + 100;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
char arr[1'002][1'002];
int N, M, K;
int sy, sx, ey, ex;
int dist[1'002][1'002];
std::queue<std::pair<int, int>> q;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::fill_n(&dist[0][0], 1'002*1'002, INF);
    std::cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
        std::cin >> arr[i];
    std::cin >> sy >> sx >> ey >> ex;
    sy--;sx--;ey--;ex--;
    dist[sy][sx] = 0;
    q.push({sy, sx});
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        int cy = cur.first;
        int cx = cur.second;
        for(int dir = 0; dir < 4; dir++)
        {
            for(int k = 1; k <= K; k++)
            {
                int ny = cy + dy[dir] * k;
                int nx = cx + dx[dir] * k;
                if(ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == '#' || dist[cy][cx] + 1 > dist[ny][nx]) break;
                if(dist[ny][nx] < INF) continue;
                dist[ny][nx] = dist[cy][cx] + 1;
                q.push({ny, nx});
            }
        }
    }
    std::cout << (dist[ey][ex] >= INF ? -1 : dist[ey][ex]);
    return 0;
}
