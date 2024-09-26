#include <bits/stdc++.h>
int n;
std::string name, en;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  std::map<std::string, int> enters;
  for(int i = 0; i < n; i++)
  {
    std::cin >> name >> en;
    enters[name] += en == "enter" ? 1 : -1;
  }
  for(auto iter = enters.rbegin(); iter != enters.rend(); iter++)
  {
    if((*iter).second <= 0)
      continue;
    std::cout << (*iter).first <<'\n';
  }
  return 0;
}