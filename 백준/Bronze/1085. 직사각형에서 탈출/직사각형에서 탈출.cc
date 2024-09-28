#include <bits/stdc++.h>
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int x, y, w, h;
  std::cin >> x >> y >> w >> h;
  std::cout << std::min({x, w-x, y, h-y});
  return 0;
}