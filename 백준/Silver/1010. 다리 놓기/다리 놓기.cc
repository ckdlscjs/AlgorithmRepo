#include <bits/stdc++.h>
long long int T, N, M, dp[32][32];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    dp[0][0] = 1;
    for(int i = 1; i <= 30; i++)
    {
        dp[i][0] = 1;
        for(int j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    std::cin >> T;
    for(int t= 0; t < T; t++)
    {
        std::cin >> N >> M;
        std::cout << dp[M][N] << '\n';
    }
	return 0;
}