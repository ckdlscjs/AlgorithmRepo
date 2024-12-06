#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
std::string arr[12];
bool visited[14][8];
int DFS(int cy, int cx, char ch)
{
  int ret = 1;
  visited[cy][cx] = true;
  for(int dir = 0; dir < 4; dir++)
  {
    int ny = cy + dy[dir];
    int nx = cx + dx[dir];
    if(ny < 0 || nx < 0 || ny >= 12 || nx >= 6 || arr[ny][nx] != ch || visited[ny][nx]) continue;
    ret += DFS(ny, nx, ch);
  }
  return ret;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  for(int i = 0; i < 12; i++) std::cin >> arr[i];
  int cnt = 0;
  while(1)
  {
    bool chk = false;
    for(int j = 0; j < 6; j++)
    {
      for(int i = 11; i >= 0; i--)
      {
        if(arr[i][j] == '.' || visited[i][j]) continue;
        if(DFS(i, j, arr[i][j]) >= 4)
        {
          chk = true;
          char ch = arr[i][j];
          std::queue<std::pair<int, int>> q;
          q.push({i, j});
          while(q.size())
          {
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();
            arr[cy][cx] = '.';
            for(int dir = 0; dir < 4; dir++)
            {
              int ny = cy + dy[dir];
              int nx = cx + dx[dir];
              if(ny < 0 || nx < 0 || ny >= 12 || nx >= 6 || arr[ny][nx] != ch) continue;
              q.push({ny, nx});
            }
          }
        }
      }
    }
    if(!chk) break;
    cnt++;
    for(int j = 0; j < 6; j++)
    {
      for(int i = 11; i >= 0; i--)
      {
        if(arr[i][j] != '.') continue;
        for(int ii = i - 1; ii >= 0; ii--)
        {
          if(arr[ii][j] == '.') continue;
          arr[i][j] = arr[ii][j];
          arr[ii][j] = '.';
          break;
        }
      }
    }
    std::memset(visited, false, sizeof(visited));
  }
  std::cout << cnt;
  return 0;
}