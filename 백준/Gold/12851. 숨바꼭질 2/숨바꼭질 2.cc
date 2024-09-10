#include <bits/stdc++.h>
using namespace std;
int n, k;
int dp[100005];
int cnt[100005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> k;
  dp[n] = 1;
  cnt[n] = 1;
  std::queue<int> q;
  q.push(n);
  while(q.size())
  {
    int cur = q.front();
    q.pop();
    for(const auto& iter : {cur-1, cur+1, cur*2})
    {
      if(iter < 0 || iter > 100000)
        continue;
      if(!dp[iter])
      {
          dp[iter] = dp[cur] + 1;
          q.push(iter);
          cnt[iter] += cnt[cur];
      }
      else if(dp[iter] == dp[cur] + 1)
          cnt[iter] += cnt[cur];
    }
  }
  std::cout << dp[k] - 1 <<'\n';
  std::cout << cnt[k];
  return 0;
}