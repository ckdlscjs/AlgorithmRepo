#include <bits/stdc++.h>
using namespace std;
const int MaxVal = 125;
int dp[43][MaxVal];
int solution(vector<vector<int>> info, int n, int m) 
{
    std::fill_n(&dp[0][0], 43*MaxVal, MaxVal);
    dp[0][0] = 0;
    for(int i = 1; i <= info.size(); i++)
    {
        for(int j = 0; j < m; j++)
        {
            dp[i][j] = std::min(dp[i][j], dp[i-1][j] + info[i-1][0]);
            if(j + info[i-1][1] < m)
                dp[i][j + info[i-1][1]] = std::min(dp[i][j + info[i-1][1]], dp[i-1][j]);
        }
    }
    int MinVal = MaxVal;
    for(int j = 0; j < m; j++)
        if(dp[info.size()][j] < n)
            MinVal = std::min(MinVal, dp[info.size()][j]);
    return MinVal >= MaxVal ? -1 : MinVal;
}