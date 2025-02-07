#include <bits/stdc++.h>
using namespace std;
int M, Q, n, x, f[20][200'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> M;
  for(int m = 1; m <= M; m++) std::cin >> f[0][m];
  for(int p = 1; p < 20; p++)
    for(int m = 1; m <= M; m++)
      f[p][m] = f[p-1][f[p-1][m]];
  std::cin >> Q;
  for(int q = 0; q < Q; q++)
  {
    std::cin >> n >> x;
    for(int p = 19; p >= 0; p--)
    {
      if(n >= (1 << p))
      {
        n -= (1 << p);
        x = f[p][x];
      }
    }
    std::cout << x << '\n';
  }
  return 0;
}
