#include <bits/stdc++.h>

using namespace std;
int solution(int m, int n, vector<string> board) 
{
    int answer = 0;
    bool chk = true;
    while(chk)
    {
        chk = false;
        std::queue<std::pair<int, int>> q;
        for(int i = 0; i < board.size()-1; i++)
        {
            for(int j = 0; j < board[0].size()-1; j++)  
            {
                if(board[i][j] == -1) continue;
                if(
                    board[i][j] == board[i][j+1] &&
                    board[i][j] == board[i+1][j] &&
                    board[i][j] == board[i+1][j+1]
                  )
                    q.push({i, j});
            }
        }
        while(q.size())
        {
            chk = true;
            auto ij = q.front();
            q.pop();
            board[ij.first][ij.second] = -1;
            board[ij.first+1][ij.second] = -1;
            board[ij.first][ij.second+1] = -1;
            board[ij.first+1][ij.second+1] = -1;
        }
        if(chk)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                std::queue<char> chs;
                for(int i = board.size()-1; i >= 0; i--)
                    if(board[i][j] != -1)
                        chs.push(board[i][j]);
                for(int i = board.size()-1; i >= 0; i--)
                {
                    if(chs.size())
                    {
                        board[i][j] = chs.front();
                        chs.pop();
                    }
                    else
                    {
                        board[i][j] = -1;
                    }     
                }
            }
        }
    }
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == -1)
                answer++;
        }
    }
    
    return answer;
}