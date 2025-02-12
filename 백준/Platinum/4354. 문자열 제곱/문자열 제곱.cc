#include <bits/stdc++.h>
std::string s;
std::vector<int> makeTable(const std::string& pattern)
{
  std::vector<int> table(pattern.size(), 0);
  int j = 0;
  for(int i = 1; i < pattern.size(); i++)
  {
    while(j > 0 && pattern[i] != pattern[j])
      j = table[j-1];
    if(pattern[i] == pattern[j])
      table[i] = ++j;
  }
  /*
  for(const auto& iter : table)
    std::cout <<iter << ' ';
  std::cout << '\n';
  */
  return table;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  while(std::cin >> s && !(s[0] == '.'))
  {
    std::vector<int> table = makeTable(s);
    int repeat = s.size() - table[s.size()-1];
    if(s.size() % repeat) std::cout << 1;
    else std::cout <<  s.size() / repeat;
    std::cout <<'\n';
  }
  return 0;
}
