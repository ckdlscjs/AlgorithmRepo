#include <bits/stdc++.h>
int n, k;
const int MaxN = 105;
std::pair<int, int> goods[MaxN];
int dp[105][100005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); 
  std::cout.tie(0);
  std::cin >> n >> k;
  for(int i = 1; i <= n; i++)
  {
    int w, v;
    std::cin >> w >> v;
    goods[i].first = w;
    goods[i].second = v;
  }
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= k; j++)
    {
      if(j < goods[i].first) dp[i][j] = dp[i-1][j];
      else dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-goods[i].first] + goods[i].second);
    }
  }
  std::cout << dp[n][k];
  return 0;
}