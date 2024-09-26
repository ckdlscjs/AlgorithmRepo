#include <bits/stdc++.h>
int n, m, input;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::unordered_map<int, int> inputs;
  std::cin >> n;
  for(int i = 0; i < n; i++)
  {
    std::cin >> input;
    inputs[input]++;
  }
  std::cin >> m;
  for(int i = 0; i < m; i++)
  {
    std::cin >> input;
    std::cout << (inputs[input] ? 1 : 0) << ' ';
  }
  return 0;
}