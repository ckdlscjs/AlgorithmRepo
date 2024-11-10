#include <bits/stdc++.h>
int N, res, arr[1005], dp[1005];
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> arr[i];
    dp[i] = arr[i];
    for(int j = 0; j < i; j++)
    {
      if(arr[j] < arr[i])
      {
        dp[i] = std::max(dp[i], dp[j] + arr[i]);
        
      }
    }
    res = std::max(res, dp[i]);
  }
  std::cout << res;
  return 0;
}