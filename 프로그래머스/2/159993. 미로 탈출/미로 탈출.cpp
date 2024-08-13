#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
char Map[105][105];
int n, m;
int Sy, Sx, Ly, Lx, Ey, Ex;
int bfs(int sy, int sx, int ey, int ex)
{
    int dist[105][105];
    std::memset(dist, 0, sizeof(dist));
    std::queue<std::pair<int, int>> q;
    q.push({sy, sx});
    dist[sy][sx] = 1;
    while(q.size())
    {
        std::pair<int, int> cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || Map[ny][nx] == 'X' || dist[ny][nx])
                continue;
            dist[ny][nx] = dist[cur.first][cur.second] + 1;
            q.push({ny, nx});
        }
    }
    return dist[ey][ex] == 0 ? -1 : dist[ey][ex]-1;
}
int solution(vector<string> maps) 
{
    n = maps.size();
    m = maps[0].size();
    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j < maps[i].size(); j++)
        {
            Map[i][j] = maps[i][j];
            if(Map[i][j] == 'S')
            {
                Sy = i;
                Sx = j;
            }
            if(Map[i][j] == 'L')
            {
                Ly = i;
                Lx = j;
            }
            if(Map[i][j] == 'E')
            {
                Ey = i;
                Ex = j;
            }
        }
            
    }
    int num1 = bfs(Sy, Sx, Ly, Lx);
    int num2 = bfs(Ly, Lx, Ey, Ex);
    if(num1 == -1 || num2 == -1)
        return -1;
    return num1 + num2;
}