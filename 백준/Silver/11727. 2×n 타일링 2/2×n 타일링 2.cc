#include <bits/stdc++.h>
long long int dp[1'005];
int n;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    for(int i = 4; i <= n; i++)
        dp[i] = (dp[i-1] + 2*dp[i-2])%10'007;
    std::cout << dp[n];
    return 0;
}