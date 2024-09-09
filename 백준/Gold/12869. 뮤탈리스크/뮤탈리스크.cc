#include <bits/stdc++.h>
using namespace std;
int n;
int dp[65][65][65];
void check(int a, int b, int c, int cnt)
{
  if(dp[a][b][c] && dp[a][b][c] <= cnt)
    return;
  dp[a][b][c] = cnt;
  if(a <= 0 && b <= 0 && c<= 0)
    return;
  check(a-9 > 0 ? a-9 : 0, b-3 > 0 ? b-3:0, c-1 > 0 ? c-1 : 0, cnt+1); //9 3 1
  check(a-9 > 0 ? a-9 : 0, b-1 > 0 ? b-1:0, c-3 > 0 ? c-3 : 0, cnt+1); //9 1 3
    
  check(a-3 > 0 ? a-3 : 0, b-9 > 0 ? b-9:0, c-1 > 0 ? c-1 : 0, cnt+1); //3 9 1
  check(a-3 > 0 ? a-3 : 0, b-1 > 0 ? b-1:0, c-9 > 0 ? c-9 : 0, cnt+1); //3 1 9
    
  check(a-1 > 0 ? a-1 : 0, b-9 > 0 ? b-9:0, c-3 > 0 ? c-3 : 0, cnt+1); //1 9 3
  check(a-1 > 0 ? a-1 : 0, b-3 > 0 ? b-3:0, c-9 > 0 ? c-9 : 0, cnt+1); //1 3 9
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  std::vector<int> scvs(3, 0);
  for(int i = 0; i < n; i++)
    std::cin >> scvs[i];
  check(scvs[0], scvs[1], scvs[2], 0);
  std::cout << dp[0][0][0];
  return 0;
}