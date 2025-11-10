#include <bits/stdc++.h>
using namespace std;
int dp[2][100'002][2];  //끝값사용, 인덱스, 사용여부
int solution(vector<int> sticker)
{
    int l = sticker.size()-1;
    dp[0][1][0] = dp[0][0][1] = sticker[0];
    dp[1][1][1] = dp[0][1][1] = sticker[1];
    for(int i = 2; i < sticker.size()-1; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            dp[j][i][0] = std::max(dp[j][i-1][0], dp[j][i-1][1]);
            dp[j][i][1] = std::max(dp[j][i-2][1], dp[j][i-1][0]) + sticker[i];
        }
    }
    dp[0][l][0] = std::max(dp[0][l-1][1], dp[0][l-1][0]);
    dp[1][l][1] = std::max(dp[1][l-1][0], dp[1][l-2][1]) + sticker.back();
    return std::max(dp[0][l][0], dp[1][l][1]);
}