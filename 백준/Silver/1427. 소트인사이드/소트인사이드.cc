#include <bits/stdc++.h>
std::string str;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> str;
  std::sort(str.begin(), str.end(), [](const char& a, const char& b)
  {
    return a > b;
  });
  std::cout << str;
  return 0;
}