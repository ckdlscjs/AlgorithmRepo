#include <bits/stdc++.h>
using namespace std;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::string str;
  std::getline(std::cin, str);
  for(int i = 0; i < str.size(); i++)
  {
    int castchar = str[i];
    if('A' <= castchar && castchar <= 'Z')
    {
      castchar += 13;
      if(castchar > 'Z')
        castchar = (castchar - 'Z') + 'A' - 1;
    }
    else if('a' <= castchar && castchar <= 'z')
    {
      castchar += 13;
      if(castchar > 'z')
        castchar = (castchar - 'z') + 'a' - 1;
    }
    std::cout << (char)castchar;
  }
  return 0;
}