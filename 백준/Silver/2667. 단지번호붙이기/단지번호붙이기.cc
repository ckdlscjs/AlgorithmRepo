#include <bits/stdc++.h>
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int n, visited[30];
std::string building[30];
int DFS(int y, int x)
{
  int ret = 1;
  visited[y] |= 1 << x;
  for(int dir = 0; dir < 4; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny] & 1 << nx || building[ny][nx] == '0') continue;
    ret += DFS(ny, nx);
  }
  return ret;
}
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  for(int i = 0; i < n; i++)
    std::cin >> building[i];
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(visited[i] & 1 << j || building[i][j] == '0') continue;
      pq.push(DFS(i, j));
    }
  }
  std::cout << pq.size() << '\n';
  while(pq.size())
    std::cout << pq.top() << '\n', pq.pop();
  return 0;
}