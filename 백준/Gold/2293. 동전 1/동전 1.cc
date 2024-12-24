#include <bits/stdc++.h>
int n, k, arr[105], dp[100'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> k;
  for(int i = 0; i < n; i++) std::cin >> arr[i];
  dp[0] = 1; //자기자신을 쓰는 방법은 한가지
  for(int i = 0; i < n; i++)
  {
    for(int j = arr[i]; j <= k; j++)
      dp[j] += dp[j - arr[i]]; //현재값-해당동전을 제한경우의수값(ex, j = 10, dp[10 - 5] 5동전을 사용하고 나머지5를 구성하는 경우의수)
    
  }
  std::cout << dp[k];
  
  return 0;
}