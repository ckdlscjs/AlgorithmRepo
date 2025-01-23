#include <bits/stdc++.h>
int T, H, W;
std::string str[12];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  for(int t = 0; t < T; t++)
  {
    std::cin >> H >> W;
    for(int h = 0; h < H; h++)
    {
      std::cin >> str[h];
      for(int w = W-1; w >= 0; w--)
        std::cout << str[h][w];
      std::cout << '\n';
    }
  }
  return 0;
}