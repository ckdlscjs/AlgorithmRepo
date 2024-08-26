#include <bits/stdc++.h>
using namespace std;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int alp[30];
  std::memset(alp, 0, sizeof(alp));
  int cnt;
  std::cin >> cnt;
  for(int i = 0; i < cnt; i++)
  {
    std::string str;
    std::cin >> str;
    alp[str[0]-'a']++;
  }
  bool chk = false;
  for(int i = 0; i < 26; i++)
  {
    if(alp[i] >= 5)
    {
      chk = true;
      std::cout << (char)(i + 'a');
    }
  }
  if(!chk)
    std::cout<<"PREDAJA";
  return 0;
}