#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;
    std::cin >> T;
    for(int t = 0; t < T; t++)
    {
        int hotel[105][105];
        for(int h = 1; h < 105; h++)
        {
            int start = 100*h + 1;
            for(int w = 1; w < 105; w++)
            {
                hotel[h][w] = start++;
            }
        }
        int H, W, N, cnt = 1;
        std::cin >> H >> W >> N;
        for(int w = 1; w <= W; w++)
        {
            for(int h = 1; h <= H; h++)
            {
               if(cnt == N)
               {
                   std::cout << hotel[h][w] << '\n';
               }
               cnt++;
            }
        }
    }
    return 0;
}