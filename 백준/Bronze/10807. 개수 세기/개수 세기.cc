#include <bits/stdc++.h>
std::unordered_map<int, int> chks;
int N, val;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> val;
    chks[val]++;
  }
  std::cin >> val;
  std::cout << chks[val];
  return 0;
}