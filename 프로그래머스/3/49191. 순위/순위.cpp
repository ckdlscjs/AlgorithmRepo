#include <bits/stdc++.h>

using namespace std;
const int INF = 100 * 105;
int dp[102][102];
int solution(int n, vector<vector<int>> results) 
{
    std::fill_n(&dp[0][0], 102*102, INF);
    for(int i = 1; i <= n; i++) dp[i][i] = 0;
    for(const auto& iter : results)
    {
        dp[iter[0]][iter[1]] = 1;
        dp[iter[1]][iter[0]] = -1;
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dp[i][k] >= INF || dp[k][j] >= INF) continue;
                if(dp[i][k] == 1 && dp[k][j] == 1)
                {
                    dp[i][j] = 1;
                    dp[j][i] = -1;
                }
                else if(dp[i][k] == -1 && dp[k][j] == -1)
                {
                    dp[i][j] = -1;
                    dp[j][i] = 1;
                }
            }
        }
    }
    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        int j = 1;
        while(j <= n && dp[i][j] < INF) j++;
        answer += j > n ? 1 : 0;
    }
    
    return answer;
}