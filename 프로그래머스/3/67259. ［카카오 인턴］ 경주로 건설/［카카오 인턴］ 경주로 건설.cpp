//https://school.programmers.co.kr/learn/courses/30/lessons/67259
#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int costs[30][30][4];
int solution(vector<vector<int>> board) 
{
    int n = board.size();
    std::queue<std::pair<std::pair<int, int>, int>> q;
    std::fill_n(&costs[0][0][0], 30*30*4, 987654321);
    costs[0][0][0] = costs[0][0][1] = costs[0][0][2] = costs[0][0][3] = 1;
    q.push({{0, 0}, 0}); q.push({{0, 0}, 2});
    while(q.size())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cur = q.front().second;
        q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n || board[ny][nx])
                continue;
            int corner = (dir != cur ? 5 : 0);
            if(costs[y][x][cur] + 1 + corner < costs[ny][nx][dir])
            {
                costs[ny][nx][dir] = costs[y][x][cur] + 1 + corner;
                q.push({{ny, nx}, dir});
            }
        }
    }
    
    return (std::min({costs[n-1][n-1][0], costs[n-1][n-1][1], costs[n-1][n-1][2], costs[n-1][n-1][3]}) - 1) * 100;
}