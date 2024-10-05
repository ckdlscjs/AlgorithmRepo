#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
const int air_dy[] = {0, -1, 0, 1};
const int air_dx[] = {1, 0, -1 ,0};
int arr[55][55];
int r, c, t, sum;
std::vector<std::pair<int, int>> cleaners;
std::queue<std::pair<int, std::pair<int, int>>> dusts;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> r >> c >> t;
  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c; j++)
    {
      std::cin >> arr[i][j];
      if(!arr[i][j])
        continue;
      if(arr[i][j] == -1)
        cleaners.push_back({i, j});
      else
        dusts.push({arr[i][j], {i, j}});
    }
  }
  while(t)
  {
    sum = 0;
    std::memset(arr, 0, sizeof(arr));
    for(const auto& iter : cleaners)
      arr[iter.first][iter.second] = -1;
    while(dusts.size())
    {
      int amount = dusts.front().first;
      int amount_div = amount / 5;
      std::pair<int, int> pos = dusts.front().second;
      dusts.pop();
      for(int dir = 0; dir < 4; dir++)
      {
        int ny = pos.first + dy[dir];
        int nx = pos.second + dx[dir];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || arr[ny][nx] == -1)
          continue;
        arr[ny][nx] += amount_div;
        amount -= amount_div;
      }
      arr[pos.first][pos.second] += amount;
    }
    for(int i = 0; i < cleaners.size(); i++)
    {
      int y = cleaners[i].first;
      int x = cleaners[i].second + 1;
      int next = 0;
      int dir = 0;
      while(!(y == cleaners[i].first && x == cleaners[i].second))
      {
        int temp = arr[y][x];
        arr[y][x] = next;
        next = temp;
        int ny = y + air_dy[dir] * (i ? -1 : 1);
        int nx = x + air_dx[dir];
        if((ny == cleaners[i].first && nx == c-1) || (ny == (i ? r-1 : 0) && nx == c-1) || (ny == (i ? r-1 : 0) && nx == 0))
          dir++;
        y = ny;
        x = nx;
      }
      arr[cleaners[i].first][cleaners[i].second] = -1;
    }
    for(int i = 0; i < r; i++)
    {
      for(int j = 0; j < c; j++)
      {
        //std::cout << arr[i][j] << ' ';
        if(!arr[i][j] || arr[i][j] == -1)
          continue;
        sum += arr[i][j];
        dusts.push({arr[i][j], {i, j}});
      }
      //std::cout << '\n';
    }
    t--;
  }
  std::cout << sum;
  return 0;
}