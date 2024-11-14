#include <bits/stdc++.h>
using namespace std;
int N, r, g, b;
int dp[2][3];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> r >> g >> b;
    if(i <= 0)
    {
      dp[0][0] = r;
      dp[0][1] = g;
      dp[0][2] = b;
    }
    else if(i > 0)
    {
      
      dp[1][0] = std::min(dp[0][1], dp[0][2]) + r;
      dp[1][1] = std::min(dp[0][0], dp[0][2]) + g;
      dp[1][2] = std::min(dp[0][0], dp[0][1]) + b;
      dp[0][0] = dp[1][0];
      dp[0][1] = dp[1][1];
      dp[0][2] = dp[1][2];
    }
  }
  std::cout << std::min({dp[1][0], dp[1][1], dp[1][2]});
  return 0;
}