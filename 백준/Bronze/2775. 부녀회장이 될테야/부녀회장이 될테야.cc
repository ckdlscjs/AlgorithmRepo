#include <bits/stdc++.h>
int T, K, N, dp[15][15];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    for(int j = 1; j <= 14; j++) dp[0][j] = j;
    for(int i = 1; i <= 14; i++)
    {
        for(int j = 1; j <= 14; j++)
        {
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    std::cin >> T;
    for(int t = 0; t < T; t++)
    {
        std::cin >> K >> N;
        std::cout << dp[K][N] << '\n';
    }

    return 0;
}