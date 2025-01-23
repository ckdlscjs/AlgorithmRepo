#include <bits/stdc++.h>
std::string str;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> str;
  int cnt = 1;
  for(int i = 0; i < str.size(); i++)
    if(str[i] == ',') cnt++;
  std::cout << cnt;
  return 0;
}