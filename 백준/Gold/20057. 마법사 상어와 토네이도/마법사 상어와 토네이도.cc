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
int N, A[500][500], res;
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
            y += dy[dir];
            x += dx[dir];
            int ay = y + dy[dir];
            int ax = x + dx[dir];
            int cur = A[y][x];
            for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    if(tor[i][j] <= 0.005f) continue;
                    int amount = A[y][x] * tor[i][j];
                    if(amount == 0) continue;
                    if(y-2 + i < 0 || x-2+j < 0 || y-2+i >= N || x-2+j >= N) res += amount;
                    else A[y-2+i][x-2+j] += amount;
                    cur -= amount;
                }
            }
            if(ay < 0 || ax < 0 || ay >= N || ax >= N) res += cur;
            else A[ay][ax] += cur;
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
