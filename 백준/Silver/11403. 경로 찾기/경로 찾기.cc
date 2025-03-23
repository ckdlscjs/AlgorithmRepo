#include <bits/stdc++.h>
int N, dp[105][105];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin >> dp[i][j];
        }
    }
    for(int k = 0; k < N; k++)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(dp[i][k] == 1 && dp[k][j] == 1)
                    dp[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cout << dp[i][j] << ' ';
        }
        std::cout << '\n';
    }
    
	return 0;
}