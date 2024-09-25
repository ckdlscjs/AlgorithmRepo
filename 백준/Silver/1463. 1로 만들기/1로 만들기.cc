#include <bits/stdc++.h>
int n;
int dp[1000005];
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  dp[1] = 0;
  dp[2] = dp[3] = 1;
  for(int i = 4; i <= n; i++)
  {
    dp[i] = dp[i-1] + 1;
    if(i % 2 == 0)
      dp[i] = std::min(dp[i], dp[i / 2] + 1);
    if(i % 3 == 0)
      dp[i] = std::min(dp[i], dp[i / 3] + 1);
  }
  std::cout << dp[n];
  return 0;
}