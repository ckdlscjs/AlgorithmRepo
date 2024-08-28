#include <bits/stdc++.h>
using namespace std;
int n, m;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
std::queue<std::pair<int, int>> q;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int t;
  std::cin >> t;
  for(int test = 0; test < t; test++)
  {
    int m, n, k, result = 0;
    std::cin >> m >> n >> k;
    int arr[55][55];
    std::memset(arr, 0, sizeof(arr));
    bool dist[55][55];
    std::memset(dist, false, sizeof(dist));
    for(int cnt = 0; cnt < k; cnt++)
    {
      int x, y;
      std::cin >> x >> y;
      arr[y][x] = 1;
    }
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        if(!arr[i][j])
          continue;
        if(dist[i][j])
          continue;
        result++;
        q.push({i, j});
        dist[i][j] = true;
        while(q.size())
        {
          int y = q.front().first;
          int x = q.front().second;
          q.pop();
          for(int dir = 0; dir < 4; dir++)
          {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || dist[ny][nx] || !arr[ny][nx])
              continue;
            q.push({ny, nx});
            dist[ny][nx] = true;
          }
        }
      }
    }
    std::cout << result <<'\n';
  }
  return 0;
}