#include <bits/stdc++.h>
int N, dp[102];
std::pair<int, int> L[22];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 0; n < N; n++) std::cin >> L[n].first;
  for(int n = 0; n < N; n++) std::cin >> L[n].second;
  for(int n = 0; n < N; n++)
  {
    for(int hp = 100; hp > L[n].first; hp--)
    {
      dp[hp] = std::max(dp[hp], dp[hp-L[n].first] + L[n].second);
    }
  }
  std::cout << dp[100];
  return 0;
}