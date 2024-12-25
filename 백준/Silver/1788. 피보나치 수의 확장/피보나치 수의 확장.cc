#include <bits/stdc++.h>
long long int N, n_0, n_1, n_2;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  if(N <= 0)
  {
    n_1 = 0;
    n_0 = 1;
    for(int i = -1; i >= N; i--)
    {
      n_2 = (n_0 - n_1) % 1'000'000'000;
      n_0 = n_1% 1'000'000'000;
      n_1 = n_2% 1'000'000'000;
    }
    
    std::cout << (n_2 < 0 ? -1 : n_2 > 0 ? 1 : 0) << '\n' << std::abs(n_2);
  }
  else
  {
    n_0 = 0;
    n_1 = 1;
    n_2 = 1;
    for(int i = 2; i <= N; i++)
    {
      n_2 = (n_1 + n_0)% 1'000'000'000;
      n_0 = n_1% 1'000'000'000;
      n_1 = n_2% 1'000'000'000;
    }
    std::cout << (n_2 < 0 ? -1 : n_2 > 0 ? 1 : 0) << '\n' << std::abs(n_2);
  }
  return 0;
}