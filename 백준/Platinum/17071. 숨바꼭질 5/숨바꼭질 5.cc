#include <bits/stdc++.h>
using namespace std;
int n, k;
int dp[500005][2];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> k;
  std::memset(dp, -1, sizeof(dp));
  dp[n][0] = 0;
  std::queue<std::pair<int, int>> q;
  q.push({n, 0});
  while(q.size())
  {
    int cur = q.front().first;
    int t = q.front().second;
    q.pop();
    for(const auto& iter : {cur-1, cur+1, cur*2})
    {
      if(iter < 0 || iter > 500000 || dp[iter][(t+1)%2] != -1)
        continue;
      dp[iter][(t+1)%2] = t+1;
      q.push({iter, t+1});
    }
  }
  bool chk = false;
  for(int t = 0; t <= 500000; t++)
  {
    k += t;
    if(k > 500000)
      break;
    if(dp[k][t%2] != -1 && dp[k][t%2] <= t)
    {
      chk = true;
      std::cout << t;
      break;
    }
  }
  if(!chk)
    std::cout << -1;
  return 0;
}