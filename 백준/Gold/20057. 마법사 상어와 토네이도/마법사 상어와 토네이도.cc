#include <bits/stdc++.h>
const int dy[] = {0, 1, 0, -1};
const int dx[] = {-1, 0, 1, 0};
const int tor[4][5][5] =
{
  {
    {-1, -1, 1, -1, -1},
    {-1, 4, 3, 0, -1},
    {2, 5, -1, -1, -1},
    {-1, 4, 3, 0, -1},
    {-1, -1, 1, -1, -1}
  },
  {
    {-1, -1, -1, -1, -1},
    {-1, 0, -1, 0, -1},
    {1, 3, -1, 3, 1},
    {-1, 4, 5, 4, -1},
    {-1, -1, 2, -1, -1}
  },
  {
    {-1, -1, 1, -1, -1},
    {-1, 0, 3, 4, -1},
    {-1, -1, -1, 5, 2},
    {-1, 0, 3, 4, -1},
    {-1, -1, 1, -1, -1}
  },
  {
    {-1, -1, 2, -1, -1},
    {-1, 4, 5, 4, -1},
    {1, 3, -1, 3, 1},
    {-1, 0, -1, 0, -1},
    {-1, -1, -1, -1, -1}
  }
};
int N, arr[505][505], dir, len = 1, cnt, res;
void Tornado(int y, int x, int dir)
{
  int cur = arr[y][x];
  arr[y][x] = 0;
  int ratios[5];
  ratios[0] = std::floor(cur*0.01f);
  ratios[1] = std::floor(cur*0.02f);
  ratios[2] = std::floor(cur*0.05f);
  ratios[3] = std::floor(cur*0.07f);
  ratios[4] = std::floor(cur*0.1f);
  int amount = ratios[0]*2 + ratios[1]*2 + ratios[2] + ratios[3]*2 + ratios[4]*2;
  for(int i = -2; i <= 2; i++)
  {
    for(int j = -2; j <= 2; j++)
    {
      int ny = y + i;
      int nx = x + j;
      if(ny < 0 || nx < 0 || ny >= N || nx >= N)
      {
        if(tor[dir][i+2][j+2] == -1) 
          continue;
        res += (tor[dir][i+2][j+2] == 5 ? cur-amount : ratios[tor[dir][i+2][j+2]]);
        //std::cout << res << '\n';
      }
      else if(tor[dir][i+2][j+2] == -1)
      {
        continue;
      }
      else
      {
        arr[ny][nx] += (tor[dir][i+2][j+2] == 5 ? cur-amount : ratios[tor[dir][i+2][j+2]]);
      }
    }
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      std::cin >> arr[i][j];
  int y = N/2;
  int x = N/2;
  while(!(y == 0 && x == -1))
  {
    for(int i = 0; i < len; i++)
    {
      y += dy[dir];
      x += dx[dir];
      Tornado(y, x, dir);
      /*
      for(int ii = 0; ii < N; ii++)
      {
        for(int jj = 0; jj < N; jj++)
          std::cout << arr[ii][jj] << ' ';
        std::cout << '\n';
      }
      std::cout << "---------\n";
      */
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
  std::cout << res;
  return 0;
}