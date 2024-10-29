#include <bits/stdc++.h>

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::pair<int, int> maxval = {0, 0};
  for(int i = 0; i < 9; i++)
  {
    int val;
    std::cin >> val;
    if(val > maxval.first)
    {
      maxval.first = val;
      maxval.second = i+1;
    }
  }
  std::cout << maxval.first << '\n' << maxval.second;
  return 0;
}