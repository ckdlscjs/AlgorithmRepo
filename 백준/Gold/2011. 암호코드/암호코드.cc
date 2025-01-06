#include <bits/stdc++.h>
const long long int Mod = 1'000'000;
long long int dp[5005];
std::string str;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> str;
  dp[0] = dp[1] = 1;
  if(str[0] == '0')
  {
    std::cout << 0;
    return 0;
  }
  for(int i = 2; i <= str.size(); i++)
  {
    int num1 = (str[i-2]-48) * 10;
    int num2 = str[i-1]-48;
  
    if(num1 && num1 + num2 <= 26)
      dp[i] = (dp[i] + dp[i-2])%Mod;
    if(num2)
      dp[i] = (dp[i] + dp[i-1])%Mod;
  }
  std::cout << dp[str.size()];
  return 0;
}