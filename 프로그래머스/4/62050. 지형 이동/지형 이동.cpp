//https://school.programmers.co.kr/learn/courses/30/lessons/62050
#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
bool visited[305][305];
std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<std::pair<int, std::pair<int, int>>>> pq;
int solution(vector<vector<int>> land, int height) 
{
    int res = 0;
    pq.push({0, {0, 0}});
    while(pq.size())
    {
        int cc = pq.top().first;
        int cy = pq.top().second.first;
        int cx = pq.top().second.second;
        pq.pop();
        if(visited[cy][cx])
            continue;
        visited[cy][cx] = true;
        res += cc;
        for(int dir = 0; dir < 4; dir++)
        {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(ny < 0 || nx < 0 || ny >= land.size() || nx >= land.size() || visited[ny][nx]) continue;
            int diff = std::abs(land[cy][cx] - land[ny][nx]);
            diff = (diff <= height ? 0 : diff);
            pq.push({diff, {ny, nx}});
        }
    }
    return res;
}