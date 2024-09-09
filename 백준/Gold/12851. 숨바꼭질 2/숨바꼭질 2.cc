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
    int n1 = cur -1;
    if(0 <= n1 && n1 <= 100000)
    {
      if(!dp[n1])
        dp[n1] = dp[cur] + 1;
      if(dp[n1] == dp[cur] + 1)
        q.push(n1);
    }
    int n2 = cur +1;
    if(0 <= n2 && n2 <= 100000)
    {
       if(!dp[n2])
        dp[n2] = dp[cur] + 1;
      if(dp[n2] == dp[cur] + 1)
        q.push(n2);
    }
    int n3 = cur*2;
    if(0 <= n3 && n3 <= 100000)
    {
      if(!dp[n3])
        dp[n3] = dp[cur] + 1;
      if(dp[n3] == dp[cur] + 1)
        q.push(n3);
    }
  }
  std::cout << dp[k] - 1 <<'\n';
  std::cout << cnt;
  return 0;
}