#include <bits/stdc++.h>
int N, val, lis[1'000'005], len;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> val;
    lis[val] = lis[val-1] + 1;
    len = std::max(len, lis[val]);
  }
  std::cout << N - len;
  return 0;
}