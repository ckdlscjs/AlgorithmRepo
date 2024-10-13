#include <bits/stdc++.h>
int N;
int arr[20][20];
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool CheckQueen(int y, int x)
{
  for(int dir = 0; dir < 8; dir++)
  {
    int ny = y, nx = x;
    while(1)
    {
      ny += dy[dir];
      nx += dx[dir];
      if(ny < 0 || nx < 0 || ny >= N || nx >= N)
        break;
      if(arr[ny][nx])
        return false;
    }
  }
  return true;
}
int Check(int y)
{
  if(y >= N)
    return 1;
  int ret = 0;
  for(int j = 0; j < N; j++)
  {
    arr[y][j] = 1;
    if(CheckQueen(y, j))
      ret += Check(y+1);
    arr[y][j] = 0;
  }
  return ret;
}
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  std::cout << Check(0);
  return 0;
}