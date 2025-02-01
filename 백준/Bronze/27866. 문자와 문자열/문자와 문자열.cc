#include <bits/stdc++.h>
std::string str;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> str;
  int output;
  std::cin >> output;
  std::cout << str[output-1];
  return 0;
}