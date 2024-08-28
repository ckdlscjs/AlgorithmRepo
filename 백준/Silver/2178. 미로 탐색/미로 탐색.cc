#include <bits/stdc++.h>
using namespace std;
int n, m;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int arr[105][105];
int dist[105][105];
std::queue<std::pair<int, int>> q;
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
      arr[i][j] = str[j] -'0';
    }
  }
  q.push({0, 0});
  dist[0][0] = 1;
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
      dist[ny][nx] = dist[y][x] + 1;
    }
  }
  std::cout << dist[n-1][m-1];
  return 0;
}