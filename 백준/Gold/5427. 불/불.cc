#include <bits/stdc++.h>
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int T, w, h, arr[1005][1005], dist[1005][1005];
std::string str;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  for(int t = 0; t < T; t++)
  {
    std::memset(arr, 0, sizeof(arr));
    std::memset(dist, 0, sizeof(dist));
    std::cin >> w >> h;
    std::deque<std::pair<int, int>> fires;
    std::deque<std::pair<int, int>> player;
    for(int i = 0; i < h; i++)
    {
      std::cin >> str;
      for(int j = 0; j < w; j++)
      {
        arr[i][j] = str[j];
        if(arr[i][j] == '@')
        {
          player.push_back({i, j});
          dist[i][j] = 1;
        }
        else if(arr[i][j] == '*')
        {
          fires.push_back({i, j});
        }
      }
    }
    bool escape = false;
    int ext = 0;
    while(!escape && (fires.size() || player.size()))
    {
      int len = fires.size();
      for(int i = 0; i < len; i++)
      {
        int y = fires.front().first;
        int x = fires.front().second;
        fires.pop_front();
        for(int dir = 0; dir < 4; dir++)
        {
          int ny = y + dy[dir];
          int nx = x + dx[dir];
          if(ny < 0 || nx < 0 || ny >= h || nx >= w || arr[ny][nx] == '#' || arr[ny][nx] == '*') continue;
          arr[ny][nx] = '*';
          fires.push_back({ny, nx});
        }
      }
      len = player.size();
       for(int i = 0; i < len; i++)
      {
        int y = player.front().first;
        int x = player.front().second;
        player.pop_front();
        for(int dir = 0; dir < 4; dir++)
        {
          int ny = y + dy[dir];
          int nx = x + dx[dir];
          if(ny < 0 || nx < 0 || ny >= h || nx >= w)
          {
            escape = true;
            break;
          }
          if(arr[ny][nx] != '.' || dist[ny][nx]) continue;
          dist[ny][nx] = dist[y][x];
          player.push_back({ny, nx});
        }
      }
      ext++;
    }
    std::cout << (escape ? std::to_string(ext) : "IMPOSSIBLE") << '\n';
  }
  return 0;
}