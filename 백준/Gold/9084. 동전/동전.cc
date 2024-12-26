#include <bits/stdc++.h>
int T, N, arr[25], M, dp[10'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  while(T--)
  {
    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];
    std::cin >> M;
    dp[0] = 1;
    for(int i = 0; i < N; i++)
      for(int j = arr[i]; j <= M; j++)
        dp[j] += dp[j - arr[i]];
    std::cout << dp[M] << '\n';
    std::memset(dp, 0, sizeof(dp));
  }
  return 0;
}