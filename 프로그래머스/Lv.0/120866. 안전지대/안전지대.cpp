#include <string>
#include <vector>
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
using namespace std;

int solution(vector<vector<int>> board) 
{
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == 1)
            {
                for(int dir = 0; dir < 8; dir++)
                {
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];
                    if(ny < 0 || nx < 0 || ny >= board.size() || nx >= board.size())
                        continue;
                    if(board[ny][nx] == 1)
                        continue;
                    board[ny][nx] = 2;
                }
            }
        }
    }
    int answer = 0;
    
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(!board[i][j])
                answer++;
        }
    }
    return answer;
}