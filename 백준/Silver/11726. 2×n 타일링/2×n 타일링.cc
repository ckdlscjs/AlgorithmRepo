#include <iostream>

using namespace std;

int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n = 0;
  std::cin >> n;
  int dp[1005];
  dp[1] = 1;
  dp[2] = 2;
  for(int i = 3; i < 1005; i++)
  {
    dp[i] = dp[i-1] + dp[i-2];
    dp[i] %= 10007;
  }
  std::cout << dp[n];
  return 0;
}