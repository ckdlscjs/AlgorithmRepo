#include <bits/stdc++.h>
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
int T, H, W;
char arr[105][105];
bool keys[28], visited[105][105];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  for(int t = 0; t < T; t++)
  {
    int res = 0;
    std::queue<std::pair<int, int>> q;
    std::cin >> H >> W;
    for(int h = 0; h < H; h++)
    {
      std::string str;
      std::cin >> str;
      for(int w = 0; w < W; w++)
      {
        arr[h][w] = str[w];
        if(h == 0 || h == H-1 || w == 0 || w == W-1)
        {
          if(arr[h][w] == '*') 
            continue;
          else if(arr[h][w] == '$')
          {
            visited[h][w] = true;
            q.push({h, w});
            res++;
          }
          else if(arr[h][w] == '.')
          {
            visited[h][w] = true;
            q.push({h, w});
          }
          else if('a' <= arr[h][w] && arr[h][w] <= 'z')
          {
            q.push({h, w});
            visited[h][w] = true;
            keys[arr[h][w]-'a'] = true;
          }
          else
          {
            q.push({h, w});
          }
        }
      }
    }
    std::string key;
    std::cin >> key;
    if(key != "0")
      for(const auto& ch : key) keys[ch-'a'] = true;
    bool change = true;
    while(change)
    {
      change = false;
      std::set<std::pair<int, int>> nq;
      while(q.size())
      {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        if(!visited[cy][cx])
        {
          if(!keys[arr[cy][cx]-'A'])
          {
            nq.insert({cy, cx});
            continue;
          }
          visited[cy][cx] = true;
        }
        for(int dir = 0; dir < 4; dir++)
        {
          int ny = cy + dy[dir];
          int nx = cx + dx[dir];
          if(ny < 0 || nx < 0 || ny >= H || nx >= W || visited[ny][nx] || arr[ny][nx] == '*') continue;
          if(arr[ny][nx] == '$')
          {
            visited[ny][nx] = true;
            q.push({ny, nx});
            res++;
          }
          else if(arr[ny][nx] == '.')
          {
            visited[ny][nx] = true;
            q.push({ny, nx});
          }
          else if('a' <= arr[ny][nx] && arr[ny][nx] <= 'z')
          {
            visited[ny][nx] = true;
            q.push({ny, nx});
            change = true;
            keys[arr[ny][nx]-'a'] = true;
          }
          else
          {
            if(keys[arr[ny][nx]-'A'])
            {
              visited[ny][nx] = true;
              q.push({ny, nx});
            }
            else
            {
              nq.insert({ny, nx});
            }
          }
        }
      }
      for(const auto& iter : nq)
        q.push(iter);
    }
    std::cout << res << '\n';
    std::memset(keys, false, sizeof(keys));
    std::memset(visited, false, sizeof(visited));
  }
  return 0;
}