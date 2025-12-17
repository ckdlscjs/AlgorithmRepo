#include <bits/stdc++.h>

using namespace std;
int dp[100'002];
int solution(int n, vector<int> money) 
{
    dp[0] = 1;
    std::sort(money.begin(), money.end());
    for(const auto& iter : money)
    {
        for(int j = iter; j <= n; j++)
        {
            dp[j] += dp[j - iter];
            dp[j] %= 1'000'000'007;
        }
    }
    return dp[n];
}