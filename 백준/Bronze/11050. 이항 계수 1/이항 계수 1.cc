#include <bits/stdc++.h>
using namespace std;
int N, K, dp[15][15];
int binomial(int n, int k)
{
  if(k == 0 || n == k) return 1;
  if(dp[n][k]) return dp[n][k];
  return dp[n][k] = binomial(n-1, k-1) + binomial(n-1, k);
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> K;
  std::cout << binomial(N, K);
  return 0;
}