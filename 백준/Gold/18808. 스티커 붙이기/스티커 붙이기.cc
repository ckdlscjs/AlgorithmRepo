#include <bits/stdc++.h>
using namespace std;
bool board[42][42];
int N, M, K, R, C, cnts[105], arr[105][12][12], res;
std::vector<std::pair<int, int>> idxs;
void Rot90(int k, int r, int c)
{
  int temp[12][12];
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      temp[i][j] = arr[k][c-1-j][i];
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      arr[k][i][j] = temp[i][j];
}
bool CheckBoard(int sy, int sx, int k, int r, int c)
{
  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c; j++)
    {
      if(arr[k][i][j] == 1 && board[sy+i][sx+j]) return false;
    }
  }
  return true;
}
void Check(int idx, int sum)
{
  if(idx >= idxs.size())
  {
    res = std::max(res, sum);
    return;
  }
  bool flag = false;
  for(int rot = 0; rot < 4; rot++)
  {
    int r = (rot%2 == 0 ? idxs[idx].first : idxs[idx].second);
    int c = (rot%2 == 0 ? idxs[idx].second : idxs[idx].first);
    if(rot != 0)
      Rot90(idx, r, c);
    for(int i = 0; i + r <= N; i++)
    {
      for(int j = 0; j + c <= M; j++)
      {
        if(CheckBoard(i, j, idx, r, c))
        {
          for(int y = 0; y < r; y++)
          {
            for(int x = 0; x < c; x++)
            {
              if(arr[idx][y][x])
                board[y+i][x+j] = true;
            }
          }
          Check(idx+1, sum + cnts[idx]);
          return;
        }
      }
    }
  }
  Check(idx+1, sum);
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M >> K;
  for(int k = 0; k < K; k++)
  {
    std::cin >> R >> C;
    idxs.push_back({R, C});
    int cnt = 0;
    for(int i = 0; i < R; i++)
    {
      for(int j = 0; j < C; j++)
      {
        std::cin >> arr[k][i][j];
        if(arr[k][i][j])
          cnt++;
      }
    }
    cnts[k] = cnt;
    /*
    for(int rot = 0; rot < 4; rot++)
    {
      int r = (rot%2 == 0 ? idxs[k].first : idxs[k].second);
      int c = (rot%2 == 0 ? idxs[k].second : idxs[k].first);
      if(rot != 0)
        Rot90(k, r, c);
      for(int i = 0; i < r; i++)
      {
        for(int j = 0; j < c; j++)
        {
          std::cout << arr[k][i][j];
        }
        std::cout << '\n';
      }
      std::cout << '\n';
    }
    */
  }
  Check(0, 0);
  std::cout << res;
  return 0;
}