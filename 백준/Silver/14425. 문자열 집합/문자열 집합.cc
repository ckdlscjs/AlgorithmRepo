#include <bits/stdc++.h>
int n, m;
std::string str;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m;
  std::unordered_set<std::string> inputs;
  for(int i = 0; i < n; i++)
  {
    std::cin >> str;
    inputs.insert(str);
  }
  int cnt = 0;
  for(int i = 0; i < m; i++)
  {
    std::cin >> str;
    if(inputs.find(str) != inputs.end())
      cnt++;
  }
  std::cout << cnt;
  return 0;
}