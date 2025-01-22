#include <bits/stdc++.h>
int dp[1'000'005];
std::string S, T;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> S >> T;
  for(int i = 0; i < S.size(); i++)
  {
    for(int j = 0; j < T.size(); j++)
    {
      if(S[i] == T[j])
      {
        if(j == 0)
          dp[j]++;
        else if(dp[j-1] > dp[j])
          dp[j]++;
      }
    }
  }
  std::cout << dp[T.size()-1];
  return 0;
}