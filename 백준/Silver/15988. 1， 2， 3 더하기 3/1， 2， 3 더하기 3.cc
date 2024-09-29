#include <bits/stdc++.h>
long long int dp[1'000'005];
int t, input;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= 1'000'001; i++)
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%1'000'000'009;
    std::cin >> t;
    for(int i = 0; i < t; i++)
    {
        std::cin >> input;
        std::cout << dp[input] <<'\n';
    }
    return 0;
}