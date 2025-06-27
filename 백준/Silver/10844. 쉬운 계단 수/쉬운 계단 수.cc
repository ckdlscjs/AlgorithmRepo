#include <bits/stdc++.h>
const int mod = 1'000'000'000;
int N;
long long int dp[105][10];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 1; i <= 9; i++) dp[1][i] = 1;
  for(int n = 2; n <= N; n++)
  {
    dp[n][0] = dp[n-1][1];
    for(int i = 1; i <= 8; i++) dp[n][i] = (dp[n-1][i-1] + dp[n-1][i+1]) % mod;
    dp[n][9] = dp[n-1][8];
  }
  long long int res = 0;
  for(int i = 0; i <= 9; i++)
  {
    res += dp[N][i];
    res %= mod;
  }
  std::cout << res;
  return 0;
}