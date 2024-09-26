#include <bits/stdc++.h>
int a, b, c, d, e, f;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> a >> b >> c >> d >> e >> f;
  int x, y;
  for(x = -999; x <= 999; x++)
  {
    for(y = -999; y <= 999; y++)
    {
      if(a*x + b*y == c && d*x + e*y == f)
      {
        std::cout << x << ' ' << y;
        return 0;
      }
    }
  }
  return 0;
}