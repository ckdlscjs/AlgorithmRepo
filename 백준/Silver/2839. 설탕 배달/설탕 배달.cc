#include <bits/stdc++.h>
int n;
const int INF = 987654321;
int dp[5005];
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    std::fill(dp, dp+5005, INF);
    dp[3] = 1;
    dp[5] = 1;
    for(int i = 6; i <= n; i++)
    {
        dp[i] = std::min(dp[i-3], dp[i-5]) + 1;
    }
    std::cout << (dp[n] >= INF ? -1 : dp[n]);
    return 0;
}