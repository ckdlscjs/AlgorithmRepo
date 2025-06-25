#include <bits/stdc++.h>
int N, arr[305], dp[305];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 1; n <= N; n++) std::cin >> arr[n];
  dp[1] = arr[1];
  dp[2] = dp[1] + arr[2];
  for(int i = 3; i <= N; i++)
    dp[i] = std::max(arr[i] + arr[i-1] + dp[i-3], arr[i] + dp[i-2]);
  std::cout << dp[N];
  return 0;
}