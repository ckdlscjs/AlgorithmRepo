#include <bits/stdc++.h>
using namespace std;
long long int T, N, dp[105];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  dp[0] = dp[1] = dp[2] = 1;
  for(int i = 3; i <= 100; i++)
    dp[i] = dp[i-2] + dp[i-3];
  std::cin >> T;
  for(int t = 0; t < T; t++)
  {
    std::cin >> N;
    std::cout << dp[N-1] << '\n';
  }
  return 0;
}