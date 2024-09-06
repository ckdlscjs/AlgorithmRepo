#include <bits/stdc++.h>
using namespace std;
std::string str1;
std::string str2;
int dp[1005][1005];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> str1;
  std::cin >> str2;
  int res = 0;
  for(int i = 1; i <= str1.size(); i++)
  {
    for(int j = 1; j <= str2.size(); j++)
    {
      if(str1[i-1] == str2[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
      res = std::max(res, dp[i][j]);
    }
  }
  std::cout << res;
  return 0;
}