#include <bits/stdc++.h>
int N, dp[1'005][10], sum[1'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  std::fill_n(&dp[0][0], 20, 1);
  sum[1] = 10;
  for(int i = 2; i <= N; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      for(int k = 0; k <= j; k++)
      {
        dp[i][j] += dp[i-1][k];
        dp[i][j] %= 10'007;
      }
    }
    for(int j = 0; j < 10; j++)
    {
       sum[i] += dp[i][j];
       sum[i] %= 10'007;
    }
  }
  std::cout << sum[N];
  
  return 0;
}