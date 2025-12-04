#include <bits/stdc++.h>
using namespace std;
std::vector<std::vector<int>> dp;
int solution(vector<vector<int>> board)
{
    dp.resize(board.size(), std::vector<int>(board[0].size(), 0));
    int answer = 0;
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            if(!board[i][j]) continue;
            if(i >= 1 && j >= 1) dp[i][j] = std::min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + 1;
            else dp[i][j] = board[i][j];
                
            answer = std::max(dp[i][j], answer);
            //std::cout << dp[i][j] << ' ';
        }
        //std::cout << '\n';
    }
    return answer*answer;
}