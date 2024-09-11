#include <bits/stdc++.h>
using namespace std;
int r, c, k;
const int MaxN = 10;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1 ,0, 0};
char arr[MaxN][MaxN];
bool visited[MaxN][MaxN];
int cnt;
void dfs(int y, int x, int dist)
{
  visited[y][x] = true;
  if(dist == k && y == 0 && x == c-1)
    cnt++;
  for(int dir = 0; dir < 4; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || arr[ny][nx] =='T')
      continue;
    dfs(ny, nx, dist+1);
  }
  visited[y][x] = false;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> r >> c >> k;
  for(int i = 0; i < r; i++)
  {
    std::string str;
    std::cin>>str;
    for(int j = 0; j < str.size(); j++)
    {
      arr[i][j] = str[j];
    }
  }
  dfs(r-1, 0, 1);
  std::cout << cnt;
  
  return 0;
}