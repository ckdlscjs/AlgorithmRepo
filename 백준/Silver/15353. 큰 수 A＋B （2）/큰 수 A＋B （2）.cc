#include <bits/stdc++.h>
std::string str[2];
std::string res;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); 
  std::cout.tie(0);
  std::cin >> str[0] >> str[1];
  std::reverse(str[0].begin(), str[0].end());
  std::reverse(str[1].begin(), str[1].end());
  int len = std::min(str[0].size(), str[1].size());
  int carri = 0, idx = 0;
  for(idx = 0; idx < len; idx++)
  {
    int num = str[0][idx] - '0' + str[1][idx] - '0' + carri;
    carri = num / 10;
    num = num%10;
    res += (num +'0');
  }
  for(idx; idx < str[0].size(); idx++)
  {
    int num = str[0][idx] - '0' + carri;
    carri = num /10;
    num = num%10;
    res += (num +'0');
  }
  for(idx; idx < str[1].size(); idx++)
  {
    int num = str[1][idx] - '0' + carri;
    carri = num / 10;
    num = num%10;
    res += (num +'0');
  }
  if(carri)
     res += (carri + '0');
  std::reverse(res.begin(), res.end());
  std::cout << res;
  return 0;
}