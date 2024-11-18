#include <bits/stdc++.h>
using namespace std;
int T, W, pos, res, dp[1005][35][2];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T >> W;
  for(int i = 1; i <= T; i++)
  {
    std::cin >> pos;
    for(int w = 0; w <= W; w++)
    {
      if(w <= 0)
      {
        dp[i][w][0] = dp[i-1][w][0] + (pos == 1 ? 1 : 0);
      }
      else
      {
        dp[i][w][0] = std::max(dp[i-1][w][0], dp[i-1][w-1][1]) + (pos == 1 ? 1 : 0);
        dp[i][w][1] = std::max(dp[i-1][w-1][0], dp[i-1][w][1]) + (pos == 2 ? 1 : 0);
      }
      res = std::max({res, dp[i][w][0], dp[i][w][1]});
    }
  }
  std::cout << res;
  return 0;
}