#include <bits/stdc++.h>
int N, res, dp[2][505];
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 1; i <= N; i++)
  {
    for(int j = 1; j <= i; j++)
    {
      std::cin >> dp[1][j];
      dp[1][j] += std::max(dp[0][j-1], dp[0][j]);
      res = std::max(res, dp[1][j]);
    }
    for(int j = 1; j <= i; j++)
      dp[0][j] = dp[1][j];
  }
  std::cout << res;
  return 0;
}