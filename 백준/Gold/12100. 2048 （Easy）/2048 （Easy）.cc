#include <bits/stdc++.h>
using namespace std;
int n;
int res;
std::vector<std::vector<int>> MoveRight(std::vector<std::vector<int>> board)
{
  for(int i = 0; i < n; i++)
  {
    int moveidx = n - 1;
    int j = moveidx - 1;
    while(j >= 0)
    {
      if(!board[i][j])
      {
        
      }
      else if(board[i][moveidx] && board[i][moveidx] == board[i][j])
      {
        board[i][moveidx--] *= 2;
        board[i][j] = 0;
      }
      else if(board[i][moveidx] && board[i][moveidx] != board[i][j])
      {
        moveidx--;
        j = moveidx - 1;
        continue;
      }
      else if(!board[i][moveidx] && board[i][moveidx] != board[i][j])
      {
        board[i][moveidx] = board[i][j];
        board[i][j] = 0;
      }
      j--;
    }
  }
  return board;
}
std::vector<std::vector<int>> MoveLeft(std::vector<std::vector<int>> board)
{
  for(int i = 0; i < n; i++)
  {
    int moveidx = 0;
    int j = moveidx+1;
    while(j < n)
    {
      if(!board[i][j])
      {
        
      }
      else if(board[i][moveidx] && board[i][moveidx] == board[i][j])
      {
        board[i][moveidx++] *= 2;
        board[i][j] = 0;
      }
      else if(board[i][moveidx] && board[i][moveidx] != board[i][j])
      {
        moveidx++;
        j = moveidx+1;
        continue;
      }
      else if(!board[i][moveidx] && board[i][moveidx] != board[i][j])
      {
        board[i][moveidx] = board[i][j];
        board[i][j] = 0;
      }
      j++;
    }
  }
  return board;
}
std::vector<std::vector<int>> MoveSouth(std::vector<std::vector<int>> board)
{
  for(int j = 0; j < n; j++)
  {
    int moveidx = n - 1;
    int i = moveidx - 1;
    while(i >= 0)
    {
      if(!board[i][j])
      {
        
      }
      else if(board[moveidx][j] && board[moveidx][j] == board[i][j])
      {
        board[moveidx--][j] *= 2;
        board[i][j] = 0;
      }
      else if(board[moveidx][j] && board[moveidx][j] != board[i][j])
      {
        moveidx--;
        i = moveidx - 1;
        continue;
      }
      else if(!board[moveidx][j] && board[moveidx][j] != board[i][j])
      {
        board[moveidx][j] = board[i][j];
        board[i][j] = 0;
      }
      i--;
    }
  }
  return board;
}

std::vector<std::vector<int>> MoveNorth(std::vector<std::vector<int>> board)
{
  for(int j = 0; j < n; j++)
  {
    int moveidx = 0;
    int i = moveidx+1;
    while(i < n)
    {
      if(!board[i][j])
      {
        
      }
      else if(board[moveidx][j] && board[moveidx][j] == board[i][j])
      {
        board[moveidx++][j] *= 2;
        board[i][j] = 0;
      }
      else if(board[moveidx][j] && board[moveidx][j] != board[i][j])
      {
        moveidx++;
        i = moveidx+1;
        continue;
      }
      else if(!board[moveidx][j] && board[moveidx][j] != board[i][j])
      {
        board[moveidx][j] = board[i][j];
        board[i][j] = 0;
      }
      i++;
    }
  }
  return board;
}
void Check(std::vector<std::vector<int>> board, int cnt)
{
  if(cnt >= 5)
  {
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        res = std::max(board[i][j], res);
    return;
  }
    
  Check(MoveRight(board), cnt+1);
  Check(MoveLeft(board), cnt+1);
  Check(MoveSouth(board), cnt+1);
  Check(MoveNorth(board), cnt+1);
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      std::cin >> board[i][j];
  Check(board, 0);
  std::cout << res;
  return 0;
}