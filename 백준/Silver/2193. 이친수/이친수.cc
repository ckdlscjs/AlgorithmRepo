#include <bits/stdc++.h>
using namespace std;
long long int N, dp[95][2];
const long long int mod = 1e9;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  dp[1][1] = 1;
  dp[2][0] = dp[1][1] + dp[1][0];
  for(int i = 3; i <= N; i++)
  {
    dp[i][0] += dp[i-1][0] + dp[i-1][1];
    dp[i][1] += dp[i-1][0];
  }

  std::cout << dp[N][0] + dp[N][1];
  return 0;
}