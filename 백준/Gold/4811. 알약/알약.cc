#include <bits/stdc++.h>
long long int dp[62][62];
int N = 1;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  for(int w = 1; w <= 30; w++)
  {
    dp[w][0] = 1;
    for(int h = 1; h <= w; h++)
    {
      if(w > h) dp[w][h] = dp[w-1][h] + dp[w][h-1];
      else dp[w][h] = dp[w][h-1];
    }
  }
  while(std::cin >> N && N) std::cout << dp[N][N] << '\n';
  return 0;
}