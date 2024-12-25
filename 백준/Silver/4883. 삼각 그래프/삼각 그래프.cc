#include <bits/stdc++.h>
int N, dp[2][3], k = 1;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  while(std::cin >> N && N)
  {
    std::cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
    dp[0][2] += dp[0][1];
    std::cin >> dp[1][0] >> dp[1][1] >> dp[1][2];
    dp[1][0] += dp[0][1];
    dp[1][1] += std::min({dp[0][1], dp[0][2], dp[1][0]});
    dp[1][2] += std::min({dp[0][1], dp[0][2], dp[1][1]});
    dp[0][0] = dp[1][0];
    dp[0][1] = dp[1][1];
    dp[0][2] = dp[1][2];
    for(int i = 2; i < N; i++)
    {
      std::cin >> dp[1][0] >> dp[1][1] >> dp[1][2];
      dp[1][0] += std::min(dp[0][0], dp[0][1]);
      dp[1][1] += std::min({dp[0][0], dp[0][1], dp[0][2], dp[1][0]});
      dp[1][2] += std::min({dp[0][1], dp[0][2], dp[1][1]});
      dp[0][0] = dp[1][0];
      dp[0][1] = dp[1][1];
      dp[0][2] = dp[1][2];
    }
    std::cout << k++ << ". " << dp[0][1] << '\n';
  }
  return 0;
}