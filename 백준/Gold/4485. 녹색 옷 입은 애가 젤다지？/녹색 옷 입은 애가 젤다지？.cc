/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
using tiii = std::tuple<int, int, int>;
const int INF = 10 * 125;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int T, N, arr[126][126], dist[126][126];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    while(std::cin >> N)
    {
        T++;
        if(N <= 0) return 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                std::cin >> arr[i][j];
        std::fill_n(&dist[0][0], sizeof(dist) / sizeof(int), INF);
        std::priority_queue<tiii, std::vector<tiii>, std::greater<tiii>> pq;
        dist[0][0] = arr[0][0];
        pq.push({dist[0][0], 0, 0});
        while(pq.size())
        {
            auto cur = pq.top();
            pq.pop();
            int cc = std::get<0>(cur);
            int cy = std::get<1>(cur);
            int cx = std::get<2>(cur);
            if(cc > dist[cy][cx]) continue;
            for(int dir = 0; dir < 4; dir++)
            {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                if(arr[ny][nx] + dist[cy][cx] >= dist[ny][nx]) continue;
                dist[ny][nx] = arr[ny][nx] + dist[cy][cx];
                pq.push({dist[ny][nx], ny, nx});
            }
        }
        std::cout << "Problem " << T <<": " << dist[N-1][N-1] << '\n';
    }
	return 0;
}

