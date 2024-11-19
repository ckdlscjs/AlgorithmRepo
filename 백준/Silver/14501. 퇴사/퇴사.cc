#include <bits/stdc++.h>
using namespace std;
int N, dp[20], t[20], p[20];
std::pair<int, int> inputs[20];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 1; i <= N; i++)
  {
    std::cin >> t[i]>> p[i];
  }
  for(int i = N; i >= 1; i--)
  {
    if(i+t[i]-1 <= N)
      dp[i] = std::max(dp[i+1], dp[i+t[i]] + p[i]);
    else
      dp[i] = dp[i+1];
  }
  std::cout << dp[1];
  return 0;
}