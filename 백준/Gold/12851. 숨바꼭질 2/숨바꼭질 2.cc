#include <bits/stdc++.h>
using namespace std;
int n, k;
int dp[100005];
int cnt = 0;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> k;
  dp[n] = 1;
  std::queue<int> q;
  q.push(n);
  while(q.size())
  {
    int cur = q.front();
    q.pop();
    if(cur == k)
    {
      cnt++;
      continue;
    }
    for(const auto& iter : {cur-1, cur+1, cur*2})
    {
      if(iter < 0 || iter > 100000)
        continue;
      if(!dp[iter])
        dp[iter] = dp[cur] + 1;
      if(dp[iter] == dp[cur] + 1)
        q.push(iter);
    }
  }
  std::cout << dp[k] - 1 <<'\n';
  std::cout << cnt;
  return 0;
}