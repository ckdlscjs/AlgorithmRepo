#include <bits/stdc++.h>
using namespace std;
long long int N, dp[105][10];
const long long int mod = 1e9;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  for(int j = 1; j <= 9; j++)
    dp[1][j] = 1;
  std::cin >> N;
  for(int i = 2; i <= N; i++)
  {
    dp[i][0] += dp[i-1][1] % mod;
    for(int j = 1; j < 9; j++)
    {
      dp[i][j] += (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
    }
    dp[i][9] += dp[i-1][8] % mod;
  }
  long long int ret = 0;
  for(int i = 0; i <= 9; i++)
    ret += dp[N][i] % mod, ret %= mod;
  std::cout << ret;
  return 0;
}