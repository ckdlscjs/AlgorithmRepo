/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
const int dy[] = {0, 1, 0, -1};
const int dx[] = {-1, 0, 1, 0};
float tor[5][5] =
{
    {0.0f, 0.0f, 0.02f, 0.0f, 0.0f},
    {0.0f, 0.1f, 0.07f, 0.01f, 0.0f},
    {0.05f, 0.0f, 0.0f, 0.0f, 0.0f},
    {0.0f, 0.1f, 0.07f, 0.01f, 0.0f},
    {0.0f, 0.0f, 0.02f, 0.0f, 0.0f},
};
void RotateCCW()
{
    float nxt[5][5];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            nxt[i][j] = tor[j][5-i-1];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            tor[i][j] = nxt[i][j];
}
int N, A[502][502], res;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            std::cin >> A[i][j];

    int y = N/2, x = N/2, dir = 0, cnt = 1;

    while(x >= 0)
    {
        for(int c = 0; c < cnt; c++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            int cur = A[ny][nx];
            
            for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    if(tor[i][j] <= 0.005f) continue;
                    int amount = A[ny][nx] * tor[i][j];
                    if(amount == 0) continue;
                    if(ny-2 + i < 0 || nx-2+j < 0 || ny-2+i >= N || nx-2+j >= N) res += amount;
                    else A[ny-2+i][nx-2+j] += amount;
                    cur -= amount;
                }
            }
            if(ny+dy[dir] < 0 || nx+dx[dir] < 0 || ny+dy[dir] >= N || nx+dx[dir] >= N) res += cur;
            else A[ny+dy[dir]][nx+dx[dir]] += cur;
            y = ny;
            x = nx;
        }
        //std::cout << y << ' ' << x << '\n';
        RotateCCW();
        dir++;
        dir %= 4;
        if(dir % 2 == 0) cnt++;
    }
    std::cout << res;
    return 0;
}
