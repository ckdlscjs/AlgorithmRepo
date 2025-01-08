#include <bits/stdc++.h>
int N, dp[35];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  dp[0] = 1;
  dp[2] = 3;
  std::cin >> N;
  for(int i = 4; i <= N; i += 2)
  {
    dp[i] = dp[i-2] * dp[2];
    for(int j = 4; j <= i; j += 2)
      dp[i] += dp[i-j] * 2;
  }
  std::cout << dp[N];
  return 0;
}