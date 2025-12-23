#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) 
{
    int answer = 0;
    std::vector<std::vector<int>> psums(board.size()+1, std::vector<int>(board[0].size()+1, 0));
    for(const auto& iter : skill)
    {
        int amount = iter[0] == 1 ? -iter[5] : iter[5];
        int r1 = iter[1], c1 = iter[2], r2 = iter[3], c2 = iter[4];
        psums[r1][c1] += amount;
        psums[r1][c2 + 1] += -amount;
        psums[r2+1][c1] += -amount;
        psums[r2+1][c2+1] += amount;
    }
    for(int i = 0; i < board.size(); i++)
    {
        int amount = psums[i][0];
        for(int j = 1; j < board[0].size(); j++)
        {
            psums[i][j] += amount;
            amount = psums[i][j];
        }
    }
    
    for(int j = 0; j < board[0].size(); j++)
    {
        int amount = psums[0][j];
        for(int i = 1; i < board.size(); i++)
        {
            psums[i][j] += amount;
            amount = psums[i][j];
        }
    }
    
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] + psums[i][j] > 0)
                answer++;
        }
    }
    return answer;
}