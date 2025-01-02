#include <bits/stdc++.h>
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
int N, M, y, x, a, b, res;
bool visited[105][105], light[105][105];
std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> switchs;
std::set<std::pair<int, int>> routes;
void DFS(int y, int x)
{
  visited[y][x] = true;
  for(const auto& iter : switchs[{y, x}])
    light[iter.first][iter.second] = true;
  
  for(int dir = 0; dir < 4; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
    routes.insert({ny, nx});
  }
  for(const auto& iter : routes)
  {
    if(visited[iter.first][iter.second] || !light[iter.first][iter.second]) continue;
    DFS(iter.first, iter.second);
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  light[1][1] = true;
  routes.insert({1, 1});
  for(int m = 0; m < M; m++)
  {
    std::cin >> y >> x >> a >> b;
    switchs[{y, x}].push_back({a, b});
  }
  DFS(1, 1);
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      res += light[i][j] ? 1 : 0;
  std::cout << res;
  return 0;
}