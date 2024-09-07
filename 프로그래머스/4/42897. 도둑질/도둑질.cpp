#include <bits/stdc++.h>
using namespace std;
int dp[1000005][2][2];
int solution(vector<int> money) 
{
    int n = money.size();
    dp[0][0][0] = 0;
    dp[0][0][0] = 0;
    dp[0][1][0] = 0;
    dp[0][1][1] = money[0];
    
    for(int i = 1; i < n; i++)
    {
        dp[i][0][0] = std::max(dp[i-1][0][0], dp[i-1][1][0]);
        dp[i][0][1] = std::max(dp[i-1][0][1], dp[i-1][1][1]);
        dp[i][1][0] = dp[i-1][0][0] + money[i];
        if(i < n-1)
            dp[i][1][1] = dp[i-1][0][1] + money[i];
        else
            dp[i][1][1] = std::max(dp[i-1][0][1], dp[i-1][1][1]);
    }
    
    return std::max({dp[n-1][0][0], dp[n-1][0][1], dp[n-1][1][0], dp[n-1][1][1]});
}