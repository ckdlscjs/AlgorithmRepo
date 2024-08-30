#include <bits/stdc++.h>
using namespace std;
const int MaxN = 105;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int n, m;
int arr[MaxN][MaxN];
std::set<std::pair<int, int>> BFS(int y, int x)
{
  std::set<std::pair<int, int>> ret;
  bool visited[MaxN][MaxN];
  std::memset(visited, 0, sizeof(visited));
  visited[y][x] = 0;
  std::queue<std::pair<int, int>> q;
  q.push({y, x});
  while(q.size())
  {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();
    for(int dir = 0; dir < 4; dir++)
    {
      int ny = cy + dy[dir];
      int nx = cx + dx[dir];
      if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx])
        continue;
      if(arr[ny][nx])
      {
        ret.insert({ny, nx});
        continue;
      }
      visited[ny][nx] = true;
      q.push({ny, nx});
    }
  }
  return ret;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m;
  int cheese = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      std::cin >> arr[i][j];
      if(arr[i][j])
        cheese++;
    }
  }
  
  int cnt = 0;
  int cnt_chs = 0;
  while(cheese>0)
  {
    cnt_chs = cheese;
    std::set<std::pair<int, int>> chs = BFS(0, 0);
    for(const auto& iter : chs)
      arr[iter.first][iter.second] = 0;
    cheese -= chs.size();
    cnt++;
  }
  std::cout << cnt <<'\n'<<cnt_chs;
  
  return 0;
}