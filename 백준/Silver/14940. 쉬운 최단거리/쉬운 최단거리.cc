#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int n, m, sy, sx, arr[1005][1005], dist[1005][1005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      std::cin >> arr[i][j];
      if(arr[i][j] == 2)
        sy = i, sx = j;
      if(arr[i][j] == 0)
        dist[i][j] = 1;
    }
  }
  std::queue<std::pair<int, int>> q;
  q.push({sy, sx});
  dist[sy][sx] = 1;
  while(q.size())
  {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();
    for(int dir = 0; dir < 4; dir++)
    {
      int ny = cy + dy[dir];
      int nx = cx + dx[dir];
      if(ny < 0 || nx < 0 || ny >= n || nx >= m || !arr[ny][nx] || dist[ny][nx]) continue;
      dist[ny][nx] = dist[cy][cx] + 1;
      q.push({ny, nx});
    }
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      std::cout << dist[i][j] -1 << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}