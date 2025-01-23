#include <bits/stdc++.h>
int H, W;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> H >> W;
  std::cout << std::min(H, W) * 100 / 2;
  return 0;
}