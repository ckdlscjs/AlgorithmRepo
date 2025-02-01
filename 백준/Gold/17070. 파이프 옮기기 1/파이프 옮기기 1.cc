#include <bits/stdc++.h>
int N, arr[20][20], dp[3][20][20];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      std::cin >> arr[i][j];
  dp[0][1][2] = 1;
  for(int i = 1; i <= N; i++)
  {
    for(int j = 1; j <= N; j++)
    {
      if(arr[i][j] == 1) continue;
      if(arr[i][j-1] == 0)
        dp[0][i][j] += dp[0][i][j-1] + dp[2][i][j-1];
      if(arr[i-1][j] == 0)
        dp[1][i][j] += dp[1][i-1][j] + dp[2][i-1][j];
      if(arr[i-1][j-1] == 0 && arr[i-1][j] == 0 && arr[i][j-1] == 0)
        dp[2][i][j] += dp[0][i-1][j-1] + dp[1][i-1][j-1] + dp[2][i-1][j-1];
    }
  }
  std::cout << dp[0][N][N] + dp[1][N][N] + dp[2][N][N];
  return 0;
}