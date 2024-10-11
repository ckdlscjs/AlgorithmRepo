#include <bits/stdc++.h>
using namespace std;
int n, res = INT_MIN;
int arr[100'005];
int dp[100'005];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  std::cin >> n;

  for(int i = 1; i <= n; i++)
  {
    std::cin >> arr[i];
    dp[i] = std::max(dp[i-1]+arr[i], arr[i]);
    res = std::max(dp[i], res);
  }
  std::cout << res;
  return 0;
}