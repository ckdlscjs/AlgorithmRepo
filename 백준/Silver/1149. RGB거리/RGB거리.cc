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
    std::cin >> dp[1][0] >> dp[1][1] >> dp[1][2];
    dp[1][0] += std::min(dp[0][1], dp[0][2]);
    dp[1][1] += std::min(dp[0][0], dp[0][2]);
    dp[1][2] += std::min(dp[0][0], dp[0][1]);
    dp[0][0] = dp[1][0];
    dp[0][1] = dp[1][1];
    dp[0][2] = dp[1][2];
  }
  std::cout << std::min({dp[1][0], dp[1][1], dp[1][2]});
  return 0;
}