#include <bits/stdc++.h>
using namespace std;
int CheckBoard(const int N, const int M, std::vector<std::string>& board)
{
    std::set<std::pair<int, int>> erases;
    for(int i = 0; i < N-1; i++)
    {
        for(int j = 0; j < M-1; j++)
        {
            if(board[i][j] == '0') continue;
            bool chk = true;
            for(int ii = 0; ii < 2; ii++)
                for(int jj = 0; jj < 2; jj++)
                    chk &= (board[i+ii][j+jj] == board[i][j]);
            if(chk)
                erases.insert({i, j});
        }
    }
    int ret = 0;
    for(const auto& iter : erases)
    {
        for(int i = iter.first; i < iter.first + 2; i++)
        {
            for(int j = iter.second; j < iter.second + 2; j++)
            {
                if(board[i][j] == '0') continue;
                ret++;
                board[i][j] = '0';
            }
        }
    }
    return ret;
}
void MoveBoard(const int N, const int M, std::vector<std::string>& board)
{
    for(int j = 0; j < M; j++)
    {
        int i = N-1;
        while(i > 0)
        {
            if(board[i][j] != '0')
            {
                i--;
                continue;
            }
            int ii = i-1;
            for(ii; ii >= 0; ii--)
                if(board[ii][j] != '0') break;
            if(ii <= -1) break;
            board[i][j] = board[ii][j];
            board[ii][j] = '0';
            i--;
        }
    }
}
int solution(int n, int m, vector<string> board) 
{
    int answer = 0;
    while(1)
    {
        int ret = CheckBoard(n, m, board);
        if(ret == 0) break;
        answer += ret;
        MoveBoard(n, m, board);
    }
    return answer;
}