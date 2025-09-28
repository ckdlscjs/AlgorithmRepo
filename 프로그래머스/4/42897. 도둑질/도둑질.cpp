#include <bits/stdc++.h>

using namespace std;
int dp[2][1'000'002][2]; //0번째선택, i번째, 선택여부(0, 1)
int solution(vector<int> money) 
{
    dp[0][0][1] = money[0];
    dp[0][1][1] = std::max(money[1], money[0]);
    dp[1][1][1] = money[1];
    for(int i = 2; i < money.size(); i++)
    {
        dp[0][i][0] = std::max(dp[0][i-1][0], dp[0][i-1][1]);
        dp[0][i][1] = std::max(dp[0][i-1][0], dp[0][i-2][1]) + money[i];
        dp[1][i][0] = std::max(dp[1][i-1][0], dp[1][i-1][1]);
        dp[1][i][1] = std::max(dp[1][i-1][0], dp[1][i-2][1]) + money[i];
    }
    return std::max(dp[0][money.size()-1][0], dp[1][money.size()-1][1]);
}