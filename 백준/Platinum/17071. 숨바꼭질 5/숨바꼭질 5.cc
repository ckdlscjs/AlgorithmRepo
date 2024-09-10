#include <bits/stdc++.h>
using namespace std;
int n, k, turn;
int dp[500005][2];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> k;
  std::memset(dp, -1, sizeof(dp));
  std::queue<int> q;
  dp[n][turn%2] = turn;
  q.push(n);
  bool chk = false;
  while(q.size())
  {
    k += turn;
    if(k > 500000)
      break;
    if(dp[k][turn%2] != -1)
    {
      chk = true;
      break;
    }
    int qsize = q.size();
    for(int i = 0; i < qsize; i++)
    {
      int cur = q.front(); q.pop();
      for(const auto& iter : {cur-1, cur+1, cur*2})
      {
        if(iter < 0 || iter > 500000 || dp[iter][(turn + 1)%2] != -1)
          continue;
        dp[iter][(turn + 1)%2] = turn + 1;
        q.push(iter);
      }
    }
    turn++;
  }
  if(chk)
    std::cout << turn;
  else
    std::cout << -1;
  return 0;
}