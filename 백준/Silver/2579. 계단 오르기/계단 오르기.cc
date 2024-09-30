#include <bits/stdc++.h>
int dp[305];
int n;
int arr[305];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for(int i = 1; i <= n; i++)
      std::cin >> arr[i];
    if(n >= 1)
      dp[1] = arr[1];
    if(n >= 2)
      dp[2] = arr[1] + arr[2];
    for(int i = 3; i <= n; i++)
    {
      dp[i] = std::max(dp[i-2], dp[i-3] + arr[i-1]) + arr[i];
    }
    std::cout << dp[n];
    return 0;
}