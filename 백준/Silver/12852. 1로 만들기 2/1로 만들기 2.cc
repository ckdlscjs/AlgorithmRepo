#include <bits/stdc++.h>
using namespace std;
int N, dp[1'000'005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 1; i <= N; i++)
    dp[i] = i-1;
  for(int i = 2; i <= N; i++)
  {
    dp[i] = dp[i-1] + 1;
    if(i%2 == 0)
      dp[i] = std::min(dp[i], dp[i/2] + 1);
    if(i%3 == 0)
      dp[i] = std::min(dp[i], dp[i/3] + 1);
  }
  std::cout << dp[N] << '\n';
  while(N)
  {
    std::cout << N << ' ';
    if(N%3 == 0 && dp[N/3] == dp[N] - 1)
      N = N/3;
    else if(N % 2 == 0 && dp[N/2] == dp[N] - 1)
      N = N/2;
    else 
      N = N-1;
  }

  return 0;
}