#include <bits/stdc++.h>
int n, m, input;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m;
  std::unordered_set<int> a;
  for(int i = 0; i < n; i++)
  {
    std::cin >> input;
    a.insert(input);
  }
  std::unordered_set<int> dupli;
  for(int i = 0; i < m; i++)
  {
    std::cin >> input;
    if(a.find(input) != a.end())
      dupli.insert(input);
  }
  std::cout << n + m - dupli.size() * 2;
  
  return 0;
}