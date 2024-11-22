#include <bits/stdc++.h>
using namespace std;
int N, M, cur, prv, res = 1, dp[45];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  for(int i = 3; i <= 40; i++) dp[i] = dp[i-1] + dp[i-2];
  std::cin >> N >> M;
  for(int i = 0; i < M; i++)
  {
    std::cin >> cur;
    res *= dp[cur - prv - 1];
    prv = cur;
  }
  res *= dp[N-prv];
  std::cout << res;
  return 0;
}