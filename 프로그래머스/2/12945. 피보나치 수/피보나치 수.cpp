#include <bits/stdc++.h>
using namespace std;
int dp[100'002];
int solution(int n) 
{
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % 1'234'567;
    return dp[n];
}