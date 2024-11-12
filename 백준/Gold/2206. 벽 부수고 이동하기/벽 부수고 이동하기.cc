#include <bits/stdc++.h>
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int N, M, arr[1005][1005], dist[2][1005][1005], res = INT_MAX;
std::vector<std::pair<int, int>> walls;
std::string str;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < N; i++)
  {
    std::cin >> str;
    for(int j = 0; j < M; j++)
    {
      arr[i][j] = str[j] -'0';
      if(arr[i][j] == 1)
        walls.push_back({i, j});
    }
  }
  std::queue<std::pair<int, std::pair<int, int>>> q;
  dist[0][0][0] = 1;
  dist[1][N-1][M-1] = 1;
  q.push({0,{0, 0}});
  q.push({1,{N-1, M-1}});
  while(q.size())
  {
    int idx = q.front().first;
    int cy = q.front().second.first;
    int cx = q.front().second.second;
    q.pop();
    for(int dir = 0; dir < 4; dir++)
    {
      int ny = cy + dy[dir];
      int nx = cx + dx[dir];
      if(ny < 0 || nx < 0 || ny >= N || nx >= M || dist[idx][ny][nx]) continue;
      dist[idx][ny][nx] = dist[idx][cy][cx] + 1;
      if(arr[ny][nx] == 0)
        q.push({idx, {ny, nx}});
    }
  }
  if(dist[0][N-1][M-1]) res = dist[0][N-1][M-1];
  for(const auto& iter : walls)
  {
    if(dist[0][iter.first][iter.second] && dist[1][iter.first][iter.second])
      res = std::min(res, dist[0][iter.first][iter.second] + dist[1][iter.first][iter.second] - 1);
  }
  std::cout << (res == INT_MAX ? -1 : res);
  return 0;
}