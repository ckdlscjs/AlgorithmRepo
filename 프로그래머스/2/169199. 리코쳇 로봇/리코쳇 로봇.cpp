#include <bits/stdc++.h>

using namespace std;
std::queue<std::pair<int, int>> q;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
std::vector<std::vector<int>> dist;
int solution(vector<string> board) 
{
    int ey, ex;
    dist.resize(board.size(), std::vector<int>(board[0].size(), 0));
    for(int r = 0; r < board.size(); r++)
    {
        for(int c = 0; c < board[r].size(); c++)
        {
            if(board[r][c] == 'R')
            {
                q.push({r, c});
                dist[r][c] = 1;
            }
            if(board[r][c] == 'G')
            {
                ey = r;
                ex = c;
            }
        }
    }
    
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        int cy = cur.first;
        int cx = cur.second;
        for(int dir = 0; dir < 4; dir++)
        {
            int sy = cy;
            int sx = cx;
            while(1)
            {
                if(sy < 0 || sx < 0 || sy >= board.size() || sx >= board[0].size() || board[sy][sx] == 'D') break;
                sy += dy[dir];
                sx += dx[dir];
            }
            sy -= dy[dir];
            sx -= dx[dir];
            if(dist[sy][sx]) continue;
            dist[sy][sx] = dist[cy][cx] + 1;
            q.push({sy, sx});
        }
    }
    return dist[ey][ex]-1;
}