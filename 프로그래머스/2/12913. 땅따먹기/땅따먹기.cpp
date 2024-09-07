#include <bits/stdc++.h>
using namespace std;
int dp[4];
int solution(vector<vector<int>> land)
{
    for(int i = 0; i < land.size(); i++)
    {
        int prev[4] = {dp[0], dp[1], dp[2], dp[3]};
        dp[0] = land[i][0] + std::max({prev[1], prev[2], prev[3]});
        dp[1] = land[i][1] + std::max({prev[0], prev[2], prev[3]});
        dp[2] = land[i][2] + std::max({prev[0], prev[1], prev[3]});
        dp[3] = land[i][3] + std::max({prev[0], prev[1], prev[2]});
    }
    return std::max({dp[0], dp[1], dp[2], dp[3]});
}