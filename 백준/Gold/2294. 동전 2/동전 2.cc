#include <bits/stdc++.h>
const int INF = 987654321;
int N, K, dp[10'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::fill_n(dp, 10'005, INF);
  dp[0] = 1;
  std::cin >> N >> K;
  for(int i = 0; i < N; i++)
  {
    int val;
    std::cin >> val;
    if(val > K)
      continue;
    dp[val] = 1;
    for(int j = val+1; j <= K; j++)
    {
      dp[j] = std::min(dp[j], dp[j-val] + 1);
    }
  }
  std::cout << (dp[K] == INF ? -1 : dp[K]);
  return 0;
}