#include <bits/stdc++.h>
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
char arr[1505][1505];
int R, C, day;
bool visited[1505][1505], swans[1505][1505];
std::vector<std::pair<int, int>> L;
std::queue<std::pair<int, int>> water;
std::queue<std::pair<int, int>> swan;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> R >> C;
  for(int r = 0; r < R; r++)
  {
    std::string str;
    std::cin >> str;
    for(int c = 0; c < C; c++)
    {
      arr[r][c] = str[c];
      if(arr[r][c] == '.' || arr[r][c] == 'L')
      {
        water.push({r, c});
        visited[r][c] = true;
      }
      if(arr[r][c] == 'L')
        L.push_back({r, c});
    }
  }
  swan.push(L[0]);
  swans[L[0].first][L[0].second] = true;
  while(!swans[L[1].first][L[1].second])
  {
    std::queue<std::pair<int, int>> nxt_swan;
    while(swan.size())
    {
      auto iter = swan.front();
      swan.pop();
      for(int dir = 0; dir < 4; dir++)
      {
        int ny = iter.first + dy[dir];
        int nx = iter.second + dx[dir];
        if(ny < 0 || nx < 0 || ny >= R || nx >= C || swans[ny][nx]) continue;
        swans[ny][nx] = true;
        if(arr[ny][nx] == '.')
          swan.push({ny, nx});
        else if(arr[ny][nx] == 'X')
          nxt_swan.push({ny, nx});
      }
    }
    if(swans[L[1].first][L[1].second]) break;
    swan = nxt_swan;
    int len = water.size();
    for(int i = 0; i < len; i++)
    {
      auto iter = water.front();
      water.pop();
      for(int dir = 0; dir < 4; dir++)
      {
        int ny = iter.first + dy[dir];
        int nx = iter.second + dx[dir];
        if(ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx]) continue;
        if(arr[ny][nx] == 'X')
        {
          arr[ny][nx] = '.';
          water.push({ny, nx});
          visited[ny][nx] = true;
        }
      }
    }
    /*
    for(int r = 0; r < R; r++)
    {
      for(int c = 0; c < C; c++)
      {
        std::cout << arr[r][c];
      }
      std::cout <<'\n';
    }
    std::cout <<'\n';
    */
    day++;
  }
  std::cout << day;
  return 0;
}