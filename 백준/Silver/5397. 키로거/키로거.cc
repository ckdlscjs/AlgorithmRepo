#include <bits/stdc++.h>
using namespace std;
std::string input;
int n;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  for(int i = 0; i < n; i++)
  {
    std::list<char> str;
    std::list<char>::iterator iter = str.begin();
    std::string input;
    std::cin >> input;
    for(const auto& it : input)
    {
      if(it == '<')
      {
        if(iter == str.begin())
          continue;
        iter--;
      }
      else if(it == '>')
      {
        if(iter == str.end())
          continue;
        iter++;
      }
      else if(it == '-')
      {
        if(iter == str.begin())
          continue;
        iter = str.erase(--iter);
      }
      else
      {
        str.insert(iter, it);
      }
    }
    for(const auto& it : str)
      std::cout << it;
    std::cout <<'\n';
  }
  return 0;
}