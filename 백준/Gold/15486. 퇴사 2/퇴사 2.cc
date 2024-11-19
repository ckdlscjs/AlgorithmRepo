#include <bits/stdc++.h>
using namespace std;
int N, dp[1'500'100], t, p;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 1; i <= N; i++)
  {
    std::cin >> t >> p;
    dp[i] = std::max(dp[i], dp[i-1]);
    if(i+t-1 <= N);
      dp[i+t] = std::max(dp[i+t], dp[i] + p);
  }
  std::cout << std::max(dp[N], dp[N+1]);
  return 0;
}