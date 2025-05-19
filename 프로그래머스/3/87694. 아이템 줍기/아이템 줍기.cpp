#include <bits/stdc++.h>

using namespace std;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int arr[105][105];
int dist[105][105];
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) 
{
    for(const auto& iter : rectangle)
    {
        int lx = iter[0]*2;
        int ly = iter[1]*2;
        int rx = iter[2]*2;
        int ry = iter[3]*2;
        int sy = ly;
        int sx = lx;
        arr[sy][sx] = 1;
        int dir = 0;
        do
        {
            int ny = sy + dy[dir];
            int nx = sx + dx[dir];
            if(ny < ly || nx < lx || ny > ry || nx > rx)
            {
                dir++;
                continue;
            }
            arr[ny][nx] = 1;
            sy = ny;
            sx = nx;
        }while(!(sy == ly && sx == lx));
    }
    
    for(int i = 0; i <= 100; i++)
    {
        for(int j = 0; j <= 100; j++)
        {
            if(arr[i][j] == 1)
            {
                for(const auto& iter : rectangle)
                {
                    int lx = iter[0]*2;
                    int ly = iter[1]*2;
                    int rx = iter[2]*2;
                    int ry = iter[3]*2;
                    if(ly < i && i < ry && lx < j && j < rx)
                    {
                        arr[i][j] = 0;
                        break;
                    }
                }
            }
            //std::cout << arr[i][j] << ' ';
        }
        //std::cout << '\n';
    }
    
    dist[characterY*2][characterX*2] = 1;
    std::queue<std::pair<int, int>> q;
    q.push({characterY*2, characterX*2});
    while(q.size())
    {
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if(ny < 0 || nx < 0 || ny > 100 || nx > 100 || arr[ny][nx] == 0 || dist[ny][nx]) continue;
            dist[ny][nx] = dist[cur.first][cur.second] + 1;
            q.push({ny, nx});
        }
    }
    return (dist[itemY*2][itemX*2] -1)/2;
}