#include <bits/stdc++.h>
using namespace std;
int n, k;
std::pair<int, int> dp[100005];
int cnt = 0;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> k;
  dp[n] = std::make_pair(1, -1);
  std::queue<int> q;
  q.push(n);
  while(q.size())
  {
    int cur = q.front();
    q.pop();
    for(const auto& iter : {cur-1, cur+1, cur*2})
    {
      if(iter < 0 || iter > 100000 || dp[iter].first)
        continue;
      dp[iter] = std::make_pair(dp[cur].first + 1, cur);
      q.push(iter);
    }
  }
  std::cout << dp[k].first-1 <<'\n';
  std::stack<int> st;
  st.push(k);
  std::pair<int, int> cur = dp[k];
  while(cur.second != -1)
  {
    st.push(cur.second);
    cur = dp[cur.second];
  }
  while(st.size())
  {
    std::cout << st.top() << ' ';
    st.pop();
  }
  return 0;
}