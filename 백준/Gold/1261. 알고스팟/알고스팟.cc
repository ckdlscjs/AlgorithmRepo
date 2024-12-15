#include <bits/stdc++.h>
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
const int INF = 987654321;
int N, M, dist[105][105];
std::string arr[105];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> M >> N;
  for(int i = 0; i < N; i++)
    std::cin >> arr[i];
  std::fill_n(&dist[0][0], 105*105, INF);
  dist[0][0] = 0;
  std::queue<std::pair<int, int>> q;
  q.push({0, 0});
  while(q.size())
  {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();
    for(int dir = 0; dir < 4; dir++)
    {
      int ny = cy + dy[dir];
      int nx = cx + dx[dir];
      if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
      if(arr[ny][nx] == '0' && dist[cy][cx] < dist[ny][nx])
      {
        dist[ny][nx] = dist[cy][cx];
        q.push({ny, nx});
      }
      else if(arr[ny][nx] == '1' && dist[cy][cx] + 1 < dist[ny][nx])
      {
        dist[ny][nx] = dist[cy][cx] + 1;
        q.push({ny, nx});
      }
    }
  }
  std::cout << dist[N-1][M-1];
}