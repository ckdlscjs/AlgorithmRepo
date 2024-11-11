#include <bits/stdc++.h>
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int n, m, arr[505][505], visited[505][505];
int DFS(int y, int x)
{
  int ret = 1;
  visited[y][x] = 1;
  for(int dir = 0; dir < 4; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || !arr[ny][nx]) continue;
    ret += DFS(ny, nx);
  }
  return ret;
}
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      std::cin >> arr[i][j];
  std::pair<int, int> res;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      if(visited[i][j] || !arr[i][j]) continue;
      res.first++;
      res.second = std::max(res.second, DFS(i, j));
    }
  }
  std::cout << res.first << '\n' << res.second;
  return 0;
}