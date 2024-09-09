#include <bits/stdc++.h>
using namespace std;
int n;
std::string input;
int result = -987654321;
int Calc(int sum, std::string str)
{
  int num1 = str[1] - '0';
  int num2 = str[3] - '0';
  int res = str.size() <= 2 ? str[1] - '0' : str[2] == '+' ? num1 + num2 : str[2] == '*' ? num1*num2 : num1-num2;
  return str[0] == '+' ? sum + res : str[0] == '*' ? sum * res : sum - res;
}
void Check(std::string str, int sum)
{
  if(str.empty())
  {
    result = std::max(result, sum);
    return;
  }
  if(str.size() >= 4)
    Check(str.substr(4) ,Calc(sum, str.substr(0, 4)));
  Check(str.substr(2) , Calc(sum, str.substr(0, 2)));
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