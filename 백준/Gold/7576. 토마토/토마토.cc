#include <bits/stdc++.h>
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int M, N, maxdist, arr[1005][1005];
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> M >> N;
  std::queue<std::pair<int, int>> q;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++)
    {
      std::cin >> arr[i][j];
      if(arr[i][j] == 1)
      {
        q.push({i, j});
      }
    }
  }
  while(q.size())
  {
    std::pair<int, int> cur = q.front();
    q.pop();
    for(int dir = 0; dir < 4; dir++)
    {
      int ny = cur.first + dy[dir];
      int nx = cur.second + dx[dir];
      if(ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx]) continue;
      arr[ny][nx] = arr[cur.first][cur.second] + 1;
      maxdist = std::max(maxdist, arr[ny][nx]-1);
      q.push({ny, nx});
    }
  }
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      if(arr[i][j] == 0)
        maxdist = -1;
  std::cout << maxdist;
  return 0;
}