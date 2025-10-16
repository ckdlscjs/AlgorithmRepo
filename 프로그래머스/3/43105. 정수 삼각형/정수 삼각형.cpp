#include <bits/stdc++.h>

using namespace std;
int dp[502][502];
int solution(vector<vector<int>> triangle) 
{
    int answer = 0;
    dp[0][1] = triangle[0][0];
    for(int i = 1; i < triangle.size(); i++)
    {
        for(int j = 0; j < triangle[i].size(); j++)
        {
            dp[i][j+1] = std::max(dp[i-1][j], dp[i-1][j+1]) + triangle[i][j];
            answer = std::max(answer, dp[i][j+1]);
        }
    }
    return answer;
}