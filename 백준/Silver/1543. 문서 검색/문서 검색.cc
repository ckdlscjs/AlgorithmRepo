#include <bits/stdc++.h>
std::string str, pattern;
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
  return table;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::getline(std::cin, str, '\n');
  std::getline(std::cin, pattern, '\n');
  std::vector<int> table = makeTable(pattern);
  int res = 0, j = 0;
  for(int i = 0; i < str.size(); i++)
  {
    while(j > 0 && str[i] != pattern[j])
      j = table[j-1];
    if(str[i] == pattern[j])
    {
      if(j >= pattern.size()-1)
      {
        res++;
        j = 0;
      }
      else
      {
        j++;
      }
    }
  }
  std::cout << res;
  return 0;
}