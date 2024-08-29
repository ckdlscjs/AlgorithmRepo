#include <bits/stdc++.h>
using namespace std;
int n, m, k;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int arr[105][105];
bool visited[105][105];
int dfs(int y, int x)
{
  int ret = 1;
  visited[y][x] = true;
  for(int dir = 0; dir < 4; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || arr[ny][nx])
      continue;
    ret += dfs(ny, nx);
  }
  return ret;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m >> k;
  for(int cnt = 0; cnt < k; cnt++)
  {
    int lx, ly, rx, ry;
    std::cin >> lx >> ly >> rx >> ry;
    for(int i = ly; i < ry; i++)
    {
      for(int j = lx; j < rx; j++)
      {
        arr[i][j] = 1;
      }
    }
  }
  std::priority_queue<int, std::vector<int>, std::greater<>> pq;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      if(visited[i][j] || arr[i][j])
        continue;
      pq.push(dfs(i, j));
    }
  }
  std::cout << pq.size() <<'\n';
  while(pq.size())
  {
    std::cout << pq.top() << ' ';
    pq.pop();
  }
  return 0;
}