#include <bits/stdc++.h>
long long int N, K, dp[1005][1005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> K;
  for(int i = 1; i <= N; i++)
  {
    dp[i][1] = i;
  }
  for(int i = 2; i <= N; i++)
  {
    for(int s = 2; s <= K; s++)
    {
      dp[i][s] = (dp[i-2][s-1] + dp[i-1][s]) % 1'000'000'003;
    }
  }
  if(K == 1)
  {
    std::cout << N;
    return 0;
  }
  std::cout << (dp[N-3][K-1] + dp[N-1][K])% 1'000'000'003;
  return 0;
}