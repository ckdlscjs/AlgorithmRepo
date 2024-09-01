#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1000;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::vector<std::vector<int>> arr(MaxN, std::vector<int>(MaxN, 0));
  int n, m;
  std::cin >> n >> m;
  std::pair<int, int> result;
  int start = n*n;
  int y = 0, x = 0, dir = 0;
  while(start >= 1)
  {
    if(start == m)
    {
      result.first = y + 1;
      result.second = x + 1;
    }
    arr[y][x] = start--;
    while(start)
    {
      int ny = y + dy[dir];
      int nx = x + dx[dir];
      if(ny < 0 || nx < 0 || ny >= n || nx >= n || arr[ny][nx])
      {
        dir++;
        dir %= 4;
        continue;
      }
      y = ny;
      x = nx;
      break;
    }
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      std::cout << arr[i][j] << ' ';
    }
    std::cout <<'\n';
  }
  std::cout << result.first << ' '<< result.second;
  return 0;
}