#include <bits/stdc++.h>
using namespace std;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >>n;
  std::string str;
  std::cin >> str;
  std::string st1 = str.substr(0,str.find('*'));
  std::string st2 = str.substr(str.find('*')+1);
  for(int i = 0; i < n; i++)
  {
    std::string temp;
    std::cin >> temp;
    std::string temp1;
    std::string temp2;
    if(st1.size() <= temp.size())
    {
      temp1 = temp.substr(0, st1.size());
      temp.erase(0, st1.size());
    }
    if(st2.size() <= temp.size())
      temp2 = temp.substr(temp.size() - st2.size());
    std::cout << ((temp1 == st1 && temp2 == st2) ? "DA" : "NE") << '\n'; 
  }
  return 0;
}