/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
char arr[27][27];
std::bitset<(1<<25)> visited;
int Check(int Scnt, int cur, int idx, int mask)
{
    if(visited[mask]) return 0;
    visited[mask] = true;
    if(cur >= 7) return (Scnt >= 4);
    int ret = 0;
    for(int i = 0; i < 25; i++)
    {
        if((mask & (1 << i)) == 0) continue;
        int cy = i / 5;
        int cx = i % 5;
        for(int dir = 0; dir < 4; dir++)
        {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            int num = ny*5 + nx;
            if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
            ret += Check(Scnt + (arr[ny][nx] == 'S'), cur+1, i+1, mask | (1<<num));
        }
    }
    return ret;
}
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    for(int i = 0; i < 5; i++) std::cin >> arr[i];
    int res = 0;
    for(int i = 0; i < 25; i++)
    {
        int cy = i / 5;
        int cx = i % 5;
        int num = cy*5 + cx;
        res += Check((arr[cy][cx] == 'S'), 1, 0, (1<<num));
    }
    std::cout << res;
    return 0;
}
