#include <bits/stdc++.h>
const int INF = 105;
int N, M, dp[105][105], A, B;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    std::fill_n(&dp[0][0], 105*105, INF);
    for(int i = 1; i <= N; i++) dp[i][i] = 0;
    for(int m = 0; m < M; m++)
    {
        std::cin >> A >> B;
        dp[A][B] = 1;
        dp[B][A] = 1;
    }
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(dp[i][k] + dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }
    int cost = INF*INF;
    int idx = 0;
    for(int i = 1; i <= N; i++)
    {
        int cur = 0;
        for(int j = 1; j <= N; j++)
            cur += dp[i][j];
        if(cur < cost)
        {
            cost = cur;
            idx = i;
        }
    }
    std::cout << idx;
	return 0;
}