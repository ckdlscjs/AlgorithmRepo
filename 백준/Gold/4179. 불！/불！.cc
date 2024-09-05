#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
const int MaxN = 1005;
std::queue<std::pair<int, int>> players;
std::queue<std::pair<int, int>> fires;
bool visited_p[MaxN][MaxN];
bool visited_f[MaxN][MaxN];
char arr[MaxN][MaxN];
int r, c;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> r >> c;
  for(int i = 0; i < r; i++)
  {
    std::string str;
    std::cin >> str;
    for(int j = 0; j < str.size(); j++)
    {
      arr[i][j] = str[j];
      if(arr[i][j] == 'J')
      {
        players.push({i, j});
        visited_p[i][j] = true;
      }
      else if(arr[i][j] == 'F')
      {
        fires.push({i, j});
        visited_f[i][j] = true;
      }
    }
  }
  int cnt = 0;
  bool out = false;
  while(players.size() && !out)
  {
    cnt++;
    std::queue<std::pair<int, int>> temp_players;
    std::queue<std::pair<int, int>> temp_fires;
    while(players.size() && !out)
    {
      int y = players.front().first;
      int x = players.front().second;
      players.pop();
      if(arr[y][x] != 'J')
        continue;
      for(int dir = 0; dir < 4; dir++)
      {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c)
        {
          out = true;
          break;
        }
        if(visited_p[ny][nx] || arr[ny][nx] != '.')
          continue;
        visited_p[ny][nx] = true;
        temp_players.push({ny, nx});
        arr[ny][nx] = 'J';
      }
    }
    while(fires.size())
    {
      int y = fires.front().first;
      int x = fires.front().second;
      fires.pop();
      for(int dir = 0; dir < 4; dir++)
      {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited_f[ny][nx] || arr[ny][nx] == 'F' || arr[ny][nx] == '#')
          continue;
        visited_f[ny][nx] = true;
        temp_fires.push({ny, nx});
        arr[ny][nx] = 'F';
      }
    }
    players = temp_players;
    fires = temp_fires;
  }
  if(out)
    std::cout << cnt;
  else
    std::cout << "IMPOSSIBLE";
  return 0;
}