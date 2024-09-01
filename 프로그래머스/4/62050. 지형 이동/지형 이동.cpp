#include <bits/stdc++.h>
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
using namespace std;
struct comp
{
    bool operator()(const std::pair<int, std::pair<int, int>>& a, const std::pair<int, std::pair<int, int>>& b)
    {
        return a.first > b.first;
    }
};
std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, comp> pq;
bool visited[305][305];
int solution(vector<vector<int>> land, int height) 
{
    int answer = 0;
    pq.push({0, {0, 0}});
    while(pq.size())
    {
        int amount = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        if(visited[y][x])
            continue;
        visited[y][x] = true;
        answer += amount;
        for(int dir = 0; dir < 4; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || nx < 0 || ny >= land.size() || nx >= land[0].size() || visited[ny][nx])
                continue;
            int dist = std::abs(land[ny][nx] - land[y][x]);
            dist = dist <= height ? 0 : dist;
            pq.push({dist, {ny, nx}});
        }
    }
    return answer;
}