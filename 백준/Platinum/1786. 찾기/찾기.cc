#include <bits/stdc++.h>
std::string T, P;
std::vector<int> MakeTable(const std::string& pat)
{
  std::vector<int> table(pat.size(), 0);
  int j = 0;
  for(int i = 1; i < pat.size(); i++)
  {
    while(j > 0 && pat[i] != pat[j]) 
      j = table[j-1];
    if(pat[i] == pat[j])
      table[i] = ++j;
  }
  return table;
}
std::vector<int> KMP(const std::string& s, const std::string& p)
{
  std::vector<int> table = MakeTable(p);
  std::vector<int> ret;
  int j = 0;
  for(int i = 0; i < s.size(); i++)
  {
    while(j > 0 && s[i] != p[j])
      j = table[j-1];
    if(s[i] == p[j])
    {
      if(j == p.size()-1)
      {
        ret.push_back(i - j + 1);
        j = table[j];
      }
      else
        j++;
    }
  }
  return ret;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::getline(std::cin, T, '\n');
  std::getline(std::cin, P, '\n');
  std::vector<int> ret = KMP(T, P);
  std::cout << ret.size() << '\n';
  for(const auto& iter : ret)
    std::cout << iter <<'\n';
  return 0;
}
