/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
#define pii std::pair<int, int>
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};
const int ady[2][4] = {{0, -1, 0, 1}, {0, 1, 0, -1}};
const int adx[2][4] = {{1, 0, -1, 0}, {1, 0, -1, 0}};
int R, C, T, arr[52][52], res;
std::vector<pii> ac;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> R >> C >> T;
    for(int r = 0; r < R; r++)
    {
        for(int c = 0; c < C; c++)
        {
            std::cin >> arr[r][c];
            if(arr[r][c] == -1) ac.push_back({r, c});
        }
    }
    for(int t = 0; t < T; t++)
    {
        int nxt[52][52];
        std::memset(nxt, 0, sizeof(nxt));
        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++)
            {
                if(arr[r][c] <= 0) continue;
                int amount = arr[r][c];
                int spread = std::floor(amount / 5.0f);
                int cnt = 0;
                for(int dir = 0; dir < 4; dir++)
                {
                    int ny = r + dy[dir];
                    int nx = c + dx[dir];
                    if(ny < 0 || nx < 0 || ny >= R || nx >= C || arr[ny][nx] == -1) continue;
                    cnt++;
                    nxt[ny][nx] += spread;
                }
                nxt[r][c] += (amount - spread * cnt);
            }
        }
   
        //ac0
        int ly = 0, lx = 0, ry = ac[0].first, rx = C-1;
        int y = ac[0].first, x = ac[0].second, prv = nxt[y][x], dir = 0;
        y += ady[0][dir]; x += adx[0][dir];
        while(!(y == ac[0].first && x == ac[0].second))
        {
            int cur = nxt[y][x];
            int ny = y + ady[0][dir];
            int nx = x + adx[0][dir];
            if(ny < ly || nx < lx || ny > ry || nx > rx)
            {
                dir++;
                continue;
            }
            nxt[y][x] = prv;
            prv = cur;
            y = ny;
            x = nx;
        }
        //ac1
        ly = ac[1].first; lx = ac[1].second; ry = R-1; rx = C-1; 
        y = ac[1].first; x = ac[1].second; prv = nxt[y][x]; dir = 0;
        y += ady[1][dir]; x += adx[1][dir];
        while(!(y == ac[1].first && x == ac[1].second))
        {
            int cur = nxt[y][x];
            int ny = y + ady[1][dir];
            int nx = x + adx[1][dir];
            if(ny < ly || nx < lx || ny > ry || nx > rx)
            {
                dir++;
                continue;
            }
            nxt[y][x] = prv;
            prv = cur;
            y = ny;
            x = nx;
        }
 
        res = 0;
        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++)
            {
                arr[r][c] = nxt[r][c];
                res += arr[r][c];
            }
        }
        arr[ac[0].first][ac[0].second] = -1;
        arr[ac[1].first][ac[1].second] = -1;
    }
    std::cout << res;
    return 0;
}
