/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
#define tiii std::tuple<int, int, int>
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, dist[55][55];
char arr[55][55];
std::vector<std::pair<int, int>> doors;
std::vector<std::pair<int, int>> poss;
std::priority_queue<tiii, std::vector<tiii>, std::greater<tiii>> pq;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
        for(int j = 0; j < N; j++)
        {
            if(arr[i][j] == '#') doors.push_back({i, j});
            if(arr[i][j] == '!') poss.push_back({i, j});
        }
    }
    std::fill_n(&dist[0][0], 55*55, 55*55);
    pq.push({1, doors[0].first, doors[0].second});
    dist[doors[0].first][doors[0].second] = 1;
    while(pq.size())
    {
        auto cur = pq.top();
        pq.pop();
        int cc = std::get<0>(cur);
        int cy = std::get<1>(cur);
        int cx = std::get<2>(cur);
        //std::cout << cy << cx << '\n';
        if(dist[cy][cx] && cc > dist[cy][cx]) continue;
        for(int dir = 0; dir < 4; dir++)
        {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            while(1)
            {
                if(ny < 0 || nx < 0 || ny >= N || nx >= N || arr[ny][nx] == '*' || dist[ny][nx] < cc + 1) break;
                if(arr[ny][nx] == '#')
                {
                    dist[ny][nx] = cc + 1;
                    break;
                }
                if(arr[ny][nx] == '!')
                {
                    pq.push({cc+1, ny, nx});
                    dist[ny][nx] = cc + 1;
                }
                ny += dy[dir];
                nx += dx[dir];
            }
        }
    }
    std::cout << dist[doors[1].first][doors[1].second] - 2;
	return 0;
}

