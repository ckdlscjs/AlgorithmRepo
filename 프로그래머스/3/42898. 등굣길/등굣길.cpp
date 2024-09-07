#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
int solution(int m, int n, vector<vector<int>> puddles) 
{
    for(const auto& iter : puddles)
    {
        dp[iter[1]][iter[0]] = -1;
    }
    dp[1][1] = 1;  //시작경우의수
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int up = 0;
            int left = 0;
            if(dp[i][j] == -1)
                continue;
            up = (dp[i-1][j] == -1 ? 0 : dp[i-1][j]);
            left = (dp[i][j-1] == -1 ? 0 : dp[i][j-1]);
            dp[i][j] += (up+left) % 1000000007;
        }
    }
    return dp[n][m];
}