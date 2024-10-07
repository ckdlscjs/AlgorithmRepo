#include <bits/stdc++.h>
using namespace std;
int n, k, l, y, x, dir;
char d;
int arr[105][105];
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
std::unordered_map<int, char> dirs;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> k;
  for(int i = 0; i < k; i++)
  {
    int y, x;
    std::cin >> y >> x;
    arr[y][x] = 1;
  }
  std::cin >> l;
  for(int i = 0; i < l; i++)
  {
    std::cin >> y >> d;
    dirs[y] = d;
  }
  int res = 0;
  std::vector<std::pair<int, int>> snakes;
  snakes.push_back({1, 1});
  bool chk = true;
  while(chk)
  {
    int length = snakes.size();
    int ny = snakes[0].first + dy[dir];
    int nx = snakes[0].second + dx[dir];
    if(ny < 1 || nx < 1 || ny > n || nx > n || arr[ny][nx] == 2)
    {
      chk = false;
    }
    if(arr[ny][nx] == 1)
    {
      snakes.push_back({snakes[length-1].first, snakes[length-1].second});
      arr[ny][nx] = 0;
    }
    for(int i = 0; i < length; i++)
    {
      int tempy = snakes[i].first;
      int tempx = snakes[i].second;
      snakes[i].first = ny;
      snakes[i].second = nx;
      arr[tempy][tempx] = 0;
      arr[ny][nx] = 2;
      ny = tempy;
      nx = tempx;
    }
    arr[snakes[snakes.size()-1].first][snakes[snakes.size()-1].second] = 2;
    res++;
    if(dirs.find(res) != dirs.end())
    {
      if(dirs[res] == 'D')
        dir++;
      else
        dir--;
      if(dir < 0)
        dir += 4;
      else if(dir >= 4)
        dir -= 4;
    }
  }
  std::cout << res;
  return 0;
}