#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
struct Shark
{
  int y;
  int x;
  int s;
  int d;
  int z;
  Shark() {}
  Shark(int _y, int _x, int _s, int _d, int _z) : y(_y), x(_x), s(_s), z(_z) 
  {
    d = _d == 1 ? 0 : _d == 2 ? 2 : _d == 3 ? 1 : 3;
  }
};

Shark arr[105][105];
std::queue<Shark> sharks;
int R, C, M, r, c, s, d, z, res;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    std::cin >> R >> C >> M;
    for(int i = 0; i < M; i++)
    {
      std::cin >> r >> c >> s >> d >> z;
      arr[r][c] = Shark(r, c, s, d, z);
    }
    for(int t = 1; t <= C; t++)
    {
      for(int i = 1; i <= R; i++)
      {
        if(arr[i][t].z > 0)
        {
          res += arr[i][t].z;
          arr[i][t].y = arr[i][t].x = arr[i][t].s = arr[i][t].d = arr[i][t].z = 0;
          break;
        }
      }
      for(int i = 1; i <= R; i++)
      {
        for(int j = 1; j <= C; j++)
        {
          if(arr[i][j].z != 0)
            sharks.push(arr[i][j]);
          arr[i][j].y = arr[i][j].x = arr[i][j].s = arr[i][j].d = arr[i][j].z = 0;
        }
      }
      while(sharks.size())
      {
        Shark shark = sharks.front();
        int amount;
        sharks.pop();
        if(shark.d % 2 == 0)
        {
          amount = shark.s % ((R-1)*2);
          while(amount)
          {
            int ny = shark.y + dy[shark.d];
            if(ny < 1 || ny > R)
            {
              shark.d += 2,shark.d %= 4;
              continue;
            }
            shark.y = ny;
            amount--;
          }
        }
        else
        {
          amount = shark.s % ((C-1)*2);
          while(amount)
          {
            int nx = shark.x + dx[shark.d];
            if(nx < 1 || nx > C)
            {
              shark.d += 2,shark.d %= 4;
              continue;
            }
            shark.x = nx;
            amount--;
          }
        }
        if(arr[shark.y][shark.x].z <= shark.z)
          arr[shark.y][shark.x] = shark;
      }
    }
    std::cout << res;
    return 0;
}