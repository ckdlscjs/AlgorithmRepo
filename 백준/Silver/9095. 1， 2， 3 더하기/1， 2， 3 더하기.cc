#include <iostream>

using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int dp[20] = {0, 1, 2, 4, };
  for(int i = 4; i <= 20; i++)
  {
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
  }
  int t;
  std::cin >> t;
  for(int i = 0; i < t; i++)
  {
    int n;
    std::cin >>n;
    std::cout << dp[n] <<'\n';
  }
  return 0;
}