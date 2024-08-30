#include <bits/stdc++.h>
using namespace std;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::string str;
  std::map<char, int> alps;
  for(int i = 0; i < 26; i++)
  {
    char cur = i+'a';
    if(cur == 'a' || cur == 'e' || cur == 'i' || cur == 'o' || cur == 'u')
      alps[cur] = 1;
    else
      alps[cur] = 0;
  }
  while(std::cin >> str && str != "end")
  {
    bool chk1 = false;
    char cur = 0;
    int cnt2 = 0;
    int i = 0;
    for(i; i < str.size(); i++)
    {
      //1
      if(alps[str[i]])
        chk1 = true;
      //2
      if(alps[cur] == alps[str[i]])
      {
        cnt2++;
        if(cnt2 >= 3)
          break;
      }
      else
      {
        cnt2 = 1;
      }
      //3
      if(cur == str[i] && str[i] != 'e' && str[i] != 'o')
      {
        break;
      }
      cur = str[i];
    }
    std::cout << "<" << str;
    if(i >= str.size() && chk1)
      std::cout <<"> is acceptable." << '\n';
    else
      std::cout <<"> is not acceptable." << '\n';
  }
  return 0;
}