#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MaxN = 55;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
int arr[MaxN][MaxN];
bool visited[MaxN][MaxN];
std::map<std::pair<int, int>, std::vector<int>> walls;
int dfs(int y, int x)
{
  int ret = 1;
  visited[y][x] = true;
  for(int dir = 0; dir < 4; dir++)
  {
    if(arr[y][x] & 1 << dir)
      continue;
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx])
      continue;
    ret += dfs(ny, nx);
  }
  return ret;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); 
  std::cout.tie(0);
  std::cin >> n >> m;
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      std::cin >> arr[i][j];
      if((arr[i][j] & 1) && j-1 >= 0)
        walls[{i, j}].push_back(0);
      if((arr[i][j] & 2) && i-1 >= 0)
        walls[{i, j}].push_back(1);
      if((arr[i][j] & 4) && j+1 < n)
        walls[{i, j}].push_back(2);
      if((arr[i][j] & 8) && i+1 < m)
        walls[{i, j}].push_back(3);
    }
  }
  int res1 = 0, res2 = 0, res3 = 0;
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(visited[i][j])
        continue;
      res1++;
      res2 = std::max(res2, dfs(i, j));
    }
  }
  for(const auto& iter : walls)
  {
    
    int y = iter.first.first;
    int x = iter.first.second;
    for(const auto& val : iter.second)
    {
      std::memset(visited, false, sizeof(visited));
      int ny = y + dy[val];
      int nx = x + dx[val];
      arr[y][x] &= ~(1 << val);
      arr[ny][nx] &= ~(1 << (val + 2) % 4);
      res3 = std::max(res3, dfs(y, x));
      arr[y][x] |= 1 << val;
      arr[ny][nx] |= 1 << (val + 2) % 4;
    }
  }
  std::cout << res1 << '\n' << res2 <<'\n' << res3;
  return 0;
}