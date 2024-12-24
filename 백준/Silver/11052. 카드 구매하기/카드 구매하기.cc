#include <bits/stdc++.h>
int N, arr[10'005], dp[10'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 1; i <= N; i++)
  {
    std::cin >> arr[i];
    dp[i] = arr[i];
    for(int j = 1; j <= i; j++)
      dp[i] = std::max(dp[i], dp[i-j] + dp[j]);
  }
  std::cout << dp[N];
  return 0;
}