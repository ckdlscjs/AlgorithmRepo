#include <bits/stdc++.h>
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
using namespace std;
std::vector<std::vector<bool>> visited;
int DFS(const std::vector<std::string>& maps, int cy, int cx)
{
    int ret = maps[cy][cx] - '0';
    visited[cy][cx] = true;
    for(int dir = 0; dir < 4; dir++)
    {
        int ny = cy + dy[dir];
        int nx = cx + dx[dir];
        if(ny < 0 || nx < 0 || ny >= maps.size() || nx >= maps[0].size() || maps[ny][nx] == 'X' || visited[ny][nx]) continue;
        ret += DFS(maps, ny, nx);
    }
    return ret;
}
vector<int> solution(vector<string> maps) 
{
    visited.resize(maps.size(), std::vector<bool>(maps[0].size(), false));
    vector<int> answer;
    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j < maps[0].size(); j++)
        {
            if(maps[i][j] == 'X' || visited[i][j]) continue;
            answer.push_back(DFS(maps, i, j));
        }
    }
    std::sort(answer.begin(), answer.end());
    if(answer.empty())
        answer.push_back(-1);
    return answer;
}