#include <bits/stdc++.h>
int N, M, dp[1005][1005], arr[1005][1005], res;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 1; i <= N; i++)
  {
    std::string str;
    std::cin >> str;
    for(int j = 1; j <= M; j++)
    {
      arr[i][j] = str[j-1] - '0';
      if(arr[i][j] == 1)
        dp[i][j] = std::min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
      res = std::max(dp[i][j], res);
    }
  }
  std::cout << res * res;
  return 0;
}