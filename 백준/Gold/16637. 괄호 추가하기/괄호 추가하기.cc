#include <bits/stdc++.h>
using namespace std;
int n;
std::string input;
int result = -987654321;
int Calc(std::string str)
{
  int num1 = str[1] - '0';
  int num2 = str[3] - '0';
  return str[2] == '+' ? num1 + num2 : str[2] == '*' ? num1*num2 : num1-num2;
}
void Check(std::string str, int sum)
{
  if(str.empty())
  {
    result = std::max(result, sum);
    return;
  }
  std::string temp;
  if(str.size() >= 4)
  {
    temp = str.substr(0, 4);
    if(temp[0] == '+')
      Check(str.substr(4) ,sum + Calc(temp));
    else if(temp[0] == '*')
      Check(str.substr(4) ,sum * Calc(temp));
    else
      Check(str.substr(4) ,sum - Calc(temp));
  }
  temp = str.substr(0, 2);
  if(temp[0] == '+')
    Check(str.substr(2) ,sum + (temp[1]-'0'));
  else if(temp[0] == '*')
    Check(str.substr(2) ,sum * (temp[1]-'0'));
  else
    Check(str.substr(2) ,sum - (temp[1]-'0'));
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  std::cin >> input;
  input = "+" + input;
  Check(input, 0);
  std::cout << result;
  return 0;
}