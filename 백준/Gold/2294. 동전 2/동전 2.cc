#include <bits/stdc++.h>
int N, K, val, dp[10'005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> K;
  std::fill_n(dp, 10'005, 10'005);
  for(int n = 0; n < N; n++)
  {
    std::cin >> val;
    if(val > K) continue;
    dp[val] = 1;
    for(int j = val + 1; j <= K; j++)
    {
      dp[j] = std::min(dp[j], dp[j-val] + 1);
    }
  }
  std::cout << (dp[K] >= 10'005 ? -1 : dp[K]);
  return 0;
}