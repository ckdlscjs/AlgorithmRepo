#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> board)
{
    int answer = 0;
    for(int i = 1; i < board.size(); i++)
    {
        for(int j = 1; j < board[0].size(); j++)
        {
            if(!board[i][j])
                continue;
            board[i][j] = std::min({board[i-1][j-1], board[i-1][j], board[i][j-1]}) + 1;
        }
    }
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            answer = std::max(board[i][j], answer);
        }
    }
    return answer*answer;
}