#include <bits/stdc++.h>
int M, x, mask;
std::string str;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> M;
  for(int m = 0; m < M; m++)
  {
    std::cin >> str;
    if(str == "add")
    {
      std::cin >> x;
      mask |= (1 << (x-1));
    }
    else if(str == "remove")
    {
      std::cin >> x;
      if(mask & (1 << (x-1)))
        mask ^= (1 << (x-1));
    }
    else if(str == "check")
    {
      std::cin >> x;
      std::cout << (mask & (1 << (x-1)) ? 1 : 0) <<'\n';
    }
    else if(str == "toggle")
    {
      std::cin >> x;
      mask ^= (1 << (x-1));
    }
    else if(str == "all")
    {
      mask = (1 << 20) - 1;
    }
    else if(str == "empty")
    {
      mask = 0;
    }
  }
  return 0;
}