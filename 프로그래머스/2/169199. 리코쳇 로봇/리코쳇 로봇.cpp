#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int dist[105][105];
void dfs(vector<string>& board, int y, int x, int cur)
{
    dist[y][x] = cur;
    if(board[y][x] == 'G') return;
    for(int dir = 0; dir < 4; dir++)
    {
        int ny = y;
        int nx = x;
        while(0 <= ny && 0 <= nx && ny < board.size() && nx < board[0].size() && board[ny][nx] != 'D')
        {
            ny += dy[dir];
            nx += dx[dir];
        }
        ny -= dy[dir];
        nx -= dx[dir];
        if(dist[ny][nx] <= cur+1) continue;
        dfs(board, ny, nx, cur+1);
    }
}
int solution(vector<string> board) 
{
    std::fill_n(&dist[0][0], 105*105, INT_MAX);
    int sy, sx, ey, ex;
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == 'G')
            {
                ey = i;
                ex = j;
            }
            else if(board[i][j] == 'R')
            {
                sy = i;
                sx = j;
            }
        }
    }
    dfs(board, sy, sx, 0);
    return (dist[ey][ex] == INT_MAX ? -1 : dist[ey][ex]);
}