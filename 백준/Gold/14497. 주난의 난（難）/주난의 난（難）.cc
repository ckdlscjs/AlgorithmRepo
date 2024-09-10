#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
const int MaxN = 305;
char arr[MaxN][MaxN];
int dist[MaxN][MaxN];
int n, m;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m;
  int y1, x1, y2, x2;
  std::cin >> y1 >> x1 >> y2 >> x2;
  for(int i = 1; i <= n; i++)
  {
    std::string str;
    std::cin >> str;
    for(int j = 1; j <= m; j++)
    {
      arr[i][j] = str[j-1];
    }
  }
  std::queue<std::pair<int, int>> temp;
  std::queue<std::pair<int, int>> q;
  dist[y1][x1] = 1;
  q.push({y1, x1});
  while(!dist[y2][x2])
  {
    while(q.size())
    {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();
      for(int dir = 0; dir < 4; dir++)
      {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 1 || nx < 1 || ny > n || nx > m || dist[ny][nx])
          continue;
        dist[ny][nx] = arr[ny][nx] == '0' ? dist[y][x] : dist[y][x] + 1;
        if(arr[ny][nx] == '0')
          q.push({ny, nx});
        else if(arr[ny][nx] == '1')
          temp.push({ny, nx});
      }
    }
    while(temp.size())
    {
      q.push(temp.front());
      temp.pop();
    }
  }

  std::cout << dist[y2][x2] - 1;
  return 0;
}