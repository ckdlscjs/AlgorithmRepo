#include <bits/stdc++.h>
using namespace std;
int arr[102][102], dp[102][102];
int solution(int m, int n, vector<vector<int>> puddles) 
{
    for(const auto& iter : puddles)
        arr[iter[0]][iter[1]] = 1;
    dp[1][1] = 1;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(arr[i][j]) continue;
            dp[i][j] += (dp[i-1][j] + dp[i][j-1]) % 1'000'000'007;
        }
    }
    return dp[m][n];
}