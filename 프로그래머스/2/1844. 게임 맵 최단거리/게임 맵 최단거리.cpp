#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
std::queue<std::pair<int, int>> q;
int dist[102][102];
int solution(vector<vector<int>> maps)
{
    dist[0][0] = 1;
    q.push({0, 0});
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if(ny < 0 || nx < 0 || ny >= maps.size() || nx >= maps[0].size() || dist[ny][nx] || maps[ny][nx] == 0) continue;
            dist[ny][nx] = dist[cur.first][cur.second] + 1;
            q.push({ny, nx});
        }
    }
    return dist[maps.size()-1][maps[0].size()-1] > 0 ? dist[maps.size()-1][maps[0].size()-1] : -1;
}