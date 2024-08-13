#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int dist[105][105];
int solution(vector<vector<int>> maps)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n = maps.size();
    int m = maps[0].size();
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;
    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || !maps[ny][nx] || dist[ny][nx])
                continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }
    return dist[n-1][m-1] ? dist[n-1][m-1] : -1;
}