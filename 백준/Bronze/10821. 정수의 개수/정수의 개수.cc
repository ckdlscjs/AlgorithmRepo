#include <bits/stdc++.h>
std::string str;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> str;
  int cnt = 1;
  auto iter = str.find(',');
  while(iter != std::string::npos)
  {
    str = str.substr(iter+1);
    iter = str.find(',');
    cnt++;
  }
  std::cout << cnt;
  return 0;
}