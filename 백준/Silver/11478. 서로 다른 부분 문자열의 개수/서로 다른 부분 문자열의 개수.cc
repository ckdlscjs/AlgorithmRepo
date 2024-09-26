#include <bits/stdc++.h>
std::string str;
std::unordered_set<std::string> chk;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> str;
  for(int i = 0; i < str.size(); i++)
  {
    std::string temp = "";
    for(int j = i; j < str.size(); j++)
    {
      temp += str[j];
      chk.insert(temp);
    }
  }
  std::cout << chk.size();
  return 0;
}