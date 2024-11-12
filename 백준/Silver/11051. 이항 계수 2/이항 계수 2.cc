#include <bits/stdc++.h>
using namespace std;
long long int N, K, dp[1005][1005];
long long int binomial(int n, int k)
{
  if(k == 0 || n == k) return 1;
  if(dp[n][k]) return dp[n][k];
  return dp[n][k] = (binomial(n-1, k-1) + binomial(n-1, k)) % 10'007;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  for(int i = 0; i <= 1000; i++)
  {
    for(int k = 0; k <= i; k++)
    {
      if(k == 0 || i == k)
        dp[i][k] = 1;
      else
        dp[i][k] = (dp[i-1][k-1] + dp[i-1][k])%10'007;
    }
  }
  std::cin >> N >> K;
  std::cout << dp[N][K];
  return 0;
}