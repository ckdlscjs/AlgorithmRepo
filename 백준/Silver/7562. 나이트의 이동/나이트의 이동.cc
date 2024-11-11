#include <bits/stdc++.h>
const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int T, I, y, x, dist[305][305];
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  for(int t = 0; t < T; t++)
  {
    std::queue<std::pair<int, int>> q;
    std::memset(dist, 0, sizeof(dist));
    std::cin >> I;
    std::cin >> y >> x;
    dist[y][x] = 1;
    q.push({y, x});
    std::cin >> y >> x;
    while(q.size())
    {
      if(dist[y][x])
        break;
      std::pair<int, int> cur = q.front();
      q.pop();
      for(int dir = 0; dir < 8; dir++)
      {
        int ny = cur.first + dy[dir];
        int nx = cur.second + dx[dir];
        if(ny < 0 || nx < 0 || ny >= I || nx >= I || dist[ny][nx]) continue;
        q.push({ny, nx});
        dist[ny][nx] = dist[cur.first][cur.second] + 1;
      }
    }
    std::cout << dist[y][x] -1 << '\n';
  }
  return 0;
}