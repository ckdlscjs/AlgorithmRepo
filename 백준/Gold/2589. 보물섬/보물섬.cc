#include <bits/stdc++.h>
using namespace std;
const int MaxN = 55;
int n, m;
int arr[MaxN][MaxN];
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int result = 0;
void bfs(int y, int x)
{
  int dist[MaxN][MaxN];
  std::memset(dist, 0, sizeof(dist));
  dist[y][x] = 1;
  std::queue<std::pair<int, int>> q;
  q.push({y, x});
  while(q.size())
  {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    result = std::max(result, dist[y][x]);
    for(int dir = 0; dir < 4; dir++)
    {
      int ny = y + dy[dir];
      int nx = x + dx[dir];
      if(ny < 0 || nx < 0 || ny >= n || nx >= m || dist[ny][nx] || !arr[ny][nx])
        continue;
      dist[ny][nx] = dist[y][x] + 1;
      q.push({ny, nx});
    }
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m;
  for(int i = 0; i < n; i++)
  {
    std::string str;
    std::cin >> str;
    for(int j = 0; j < str.size(); j++)
    {
      arr[i][j] = str[j] == 'L' ? 1 : 0;
    }
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      if(arr[i][j])
        bfs(i, j);
    }
  }
  std::cout << result - 1;
  return 0;
}