#include <bits/stdc++.h>
const int diry[] = {0, 1, 0, -1};
const int dirx[] = {-1, 0, 1, 0};
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, M, arr[50][50], d, s, res[3];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  int y = N/2, x = N/2, len = 1, cnt = 0, dir = 0;
  std::vector<std::pair<int, int>> orders;
  while(!(y == 0 && x == -1))
  {
    for(int i = 0; i < len; i++)
    {
      y += diry[dir];
      x += dirx[dir];
      if(y == 0 && x == -1)
        break;
      orders.push_back({y, x});
    }
    dir++;
    dir %= 4;
    cnt++;
    if(cnt >= 2)
    {
      len++;
      cnt = 0;
    }
  }
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      std::cin >> arr[i][j];
  for(int m = 0; m < M; m++)
  {
    y = N/2, x = N/2;
    std::cin >> d >> s;
    for(int i = 1; i <= s; i++)
    {
      int ny = y + dy[d-1] * i;
      int nx = x + dx[d-1] * i;
      arr[ny][nx] = 0;
    }
    bool flag = true;
    while(flag)
    {
      flag = false;
      int cur = -1, cnt = 0, sidx;
      for(int i = 0; i < orders.size(); i++)
      {
        int cy = orders[i].first;
        int cx = orders[i].second;
        if(arr[cy][cx] == 0) continue;
        else if(arr[cy][cx] == cur) cnt++;
        else
        {
          if(cnt >= 4)
          {
            flag = true;
            res[cur-1] += cnt;
            for(int j = sidx; j < i; j++)
              arr[orders[j].first][orders[j].second] = 0;
            cnt = 1;
            cur = arr[cy][cx];
          }
          else
          {
            cur = arr[cy][cx];
            cnt = 1;
            sidx = i;
          }
        }
      }
      if(cnt >= 4)
      {
        res[cur-1] += cnt;
        for(int j = sidx; j < orders.size(); j++)
          arr[orders[j].first][orders[j].second] = 0;
      }
    }
    
    std::pair<int, int> curs(-1, -1);
    std::vector<std::pair<int, int>> vals;
    for(int i = 0; i < orders.size(); i++)
    {
      if(arr[orders[i].first][orders[i].second] == 0) continue;
      if(curs.second == -1)
      {
        curs.first = 1;
        curs.second = arr[orders[i].first][orders[i].second];
      }
      else if(curs.second == arr[orders[i].first][orders[i].second])
      {
        curs.first++;
      }
      else
      {
        vals.push_back(curs);
        curs.first = 1;
        curs.second = arr[orders[i].first][orders[i].second];
      }
    }
    vals.push_back(curs);
    int sidx = 0;
    for(const auto& iter : vals)
    {
      if(iter.first == -1) break;
      if(sidx >= orders.size()) break;
      arr[orders[sidx].first][orders[sidx++].second] = iter.first;
      if(sidx >= orders.size()) break;
      arr[orders[sidx].first][orders[sidx++].second] = iter.second;
    }
    for(sidx; sidx < orders.size(); sidx++)
      arr[orders[sidx].first][orders[sidx].second] = 0;
    /*
    for(int i = 0; i < N; i++)
    {
      for(int j = 0; j < N; j++)
      {
        std::cout << arr[i][j] << ' ';
      }
      std::cout << '\n';
    }
    std::cout << '\n';
    */
  }
  std::cout << res[0] + 2*res[1] + 3*res[2];
  return 0;
}