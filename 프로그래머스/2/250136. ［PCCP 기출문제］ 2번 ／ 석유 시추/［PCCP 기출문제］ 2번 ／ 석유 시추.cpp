//https://school.programmers.co.kr/learn/courses/30/lessons/250136
#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int amount[62'505];
int visited[505][505];
int dfs(const std::vector<std::vector<int>>& land, const int mask, int y, int x)
{
    int ret = 1;
    visited[y][x] = mask;
    for(int dir = 0; dir < 4; dir++)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || nx < 0 || ny >= land.size() || nx >= land[0].size() || visited[ny][nx] || !land[ny][nx])
            continue;
        ret += dfs(land, mask, ny, nx);
    }
    return ret;
}
int solution(vector<vector<int>> land) 
{
    int mask = 1;
    for(int i = 0; i < land.size(); i++)
    {
        for(int j = 0; j < land[i].size(); j++)
        {
            if(visited[i][j] || !land[i][j])
                continue;
            int cnt = dfs(land, mask, i, j);
            amount[mask++] = cnt;
        }
    }
    int answer = 0;
    for(int j = 0; j < land[0].size(); j++)
    {
        int sum = 0;
        std::unordered_set<int> chks;
        for(int i = 0; i < land.size(); i++)
        {
            if(!visited[i][j])
                continue;
            chks.insert(visited[i][j]);
        }
        for(const auto& iter : chks)
            sum += amount[iter];
        answer = std::max(answer, sum);
    }
    return answer;
}