#include <bits/stdc++.h>
using namespace std;
int res;
char oper = '+';
std::string str, num;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> str;
  str += '+';
  bool flag = false;
  for(const auto& ch : str)
  {
    if(std::isdigit(ch))
    {
      num += ch;
    }
    else
    {
      if(!flag)
      {
        if(oper == '+')
          res += std::stoi(num);
        else
        {
          res -= std::stoi(num);
          flag = true;
        }
      }
      else
        res -= std::stoi(num);
      num.clear();
      oper = ch;
    }
  }
  std::cout << res;
  return 0;
}