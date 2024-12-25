#include <bits/stdc++.h>
int N, dp[1'000'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  for(int i = 3; i <= N; i++)
    dp[i] = (dp[i-1] + dp[i-2]) % 15'746;
  std::cout << dp[N];
  return 0;
}