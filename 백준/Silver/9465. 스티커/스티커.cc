#include <bits/stdc++.h>
using namespace std;
int T, n, arr[2][100'005], dp[2][100'005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  for(int t = 0; t < T; t++)
  {
    std::memset(dp, 0, sizeof(dp));
    std::cin >> n;
    for(int i = 0; i < 2; i++)
      for(int j = 2; j <= n+1; j++)
        std::cin >> arr[i][j];
    for(int j = 2; j <= n+1; j++)
    {
      dp[0][j] = std::max({dp[0][j-2], dp[1][j-1], dp[1][j-2]}) + arr[0][j];
      dp[1][j] = std::max({dp[1][j-2], dp[0][j-1], dp[0][j-2]}) + arr[1][j];
    }
    std::cout << std::max(dp[0][n+1], dp[1][n+1]) << '\n';
  }
  return 0;
}