#include <bits/stdc++.h>
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int n, visited[105][105];
std::string arr[105];
void DFS(int y, int x, const char& ch)
{
  visited[y][x] = 1;
  for(int dir = 0; dir < 4; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] || arr[ny][nx] != ch) continue;
    DFS(ny, nx, ch);
  }
}
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  for(int i = 0; i < n; i++) std::cin >> arr[i];
  std::pair<int, int> res;
  std::queue<std::pair<int, int>> greens;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(arr[i][j] == 'G') greens.push({i, j});
      if(visited[i][j]) continue;
      DFS(i, j, arr[i][j]);
      res.first++;
    }
  }
  while(greens.size()) arr[greens.front().first][greens.front().second] = 'R', greens.pop();
  std::memset(visited, 0, sizeof(visited));
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(visited[i][j]) continue;
      DFS(i, j, arr[i][j]);
      res.second++;
    }
  }
  std::cout << res.first << '\n' << res.second;
  return 0;
}