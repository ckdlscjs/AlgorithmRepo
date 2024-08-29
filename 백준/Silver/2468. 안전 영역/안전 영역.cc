#include <bits/stdc++.h>
using namespace std;
int n, m;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int arr[105][105];
void dfs(bool visited[][105], int h, int y, int x)
{
  visited[y][x] = true;
  for(int dir = 0; dir < 4; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] || arr[ny][nx] <= h)
      continue;
    dfs(visited, h, ny, nx);
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      std::cin >> arr[i][j];
      m = std::max(m, arr[i][j]);
    }
  }
  int result = 0;
  for(int h = 0; h < m; h++)
  {
    int cnt = 0;
    bool visited[105][105];
    std::memset(visited, false, sizeof(visited));
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        if(visited[i][j] || arr[i][j] <= h)
          continue;
        dfs(visited, h, i, j);
        cnt++;
      }
    }
    result = std::max(result, cnt);
  }
  std::cout << result;
  return 0;
}