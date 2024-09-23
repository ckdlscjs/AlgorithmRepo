#include <bits/stdc++.h>
long long int dp[2005];
long long solution(int n) 
{
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++)
        dp[i] = (dp[i-2] + dp[i-1])%1234567;
    return dp[n];
}