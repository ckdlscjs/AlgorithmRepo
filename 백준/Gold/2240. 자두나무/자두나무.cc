#include <bits/stdc++.h>
using namespace std;
int T, W, pos, res, inputs[1005][2], dp[1005][35][2];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T >> W;
  for(int i = 1; i <= T; i++)
  {
    std::cin >> pos;
    inputs[i][pos-1] = 1;
    dp[i][0][0] += dp[i-1][0][0] + inputs[i][0];
    res = std::max(res, dp[i][0][0]);
  }
  for(int i = 1; i <= T; i++)
  {
    for(int w = 1; w <= W; w++)
    {
      dp[i][w][0] = std::max(dp[i-1][w][0], dp[i-1][w-1][1]) + inputs[i][0];
      dp[i][w][1] = std::max(dp[i-1][w-1][0], dp[i-1][w][1]) + inputs[i][1];
      res = std::max({res, dp[i][w][0], dp[i][w][1]});
    }
  }
  std::cout << res;
  return 0;
}