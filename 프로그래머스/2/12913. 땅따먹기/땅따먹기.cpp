#include <bits/stdc++.h>
using namespace std;
int dp[2][4];
int solution(vector<vector<int>> land)
{
    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];
    for(int i = 1; i < land.size(); i++)
    {
        dp[1][0] = std::max({dp[0][1], dp[0][2], dp[0][3]}) + land[i][0];
        dp[1][1] = std::max({dp[0][0], dp[0][2], dp[0][3]}) + land[i][1];
        dp[1][2] = std::max({dp[0][0], dp[0][1], dp[0][3]}) + land[i][2];
        dp[1][3] = std::max({dp[0][0], dp[0][1], dp[0][2]}) + land[i][3];
        dp[0][0] = dp[1][0]; 
        dp[0][1] = dp[1][1]; 
        dp[0][2] = dp[1][2]; 
        dp[0][3] = dp[1][3];
    }
    return std::max({dp[1][0], dp[1][1], dp[1][2], dp[1][3]});
}