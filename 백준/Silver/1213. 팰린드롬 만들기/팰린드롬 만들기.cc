#include <bits/stdc++.h>
using namespace std;
std::string str;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> str;
  int alp[30];
  std::memset(alp, 0, sizeof(alp));
  for(int i = 0; i < str.size(); i++)
    alp[str[i]-'A']++;
  int oddCount = 0;
  for(int i = 0; i < 26; i++)
    if(alp[i] % 2)
      oddCount++;
  if(oddCount < 2)
  {
    std::string res;
    char mid = 0;
    for(int i = 0; i < 26; i++)
    {
      if(alp[i] % 2)
      {
        mid = i + 'A';
        alp[i]--;
      }
      while(alp[i])
      {
        res += ('A' + i);
        alp[i] -= 2;
      }
    }
    if(mid)
      res += mid;
    int start = mid ? res.size()-2 : res.size()-1;
    for(int i = start; i >= 0; i--)
      res += res[i];
    std::cout << res;
    return 0;
  }
  std::cout <<"I'm Sorry Hansoo";
  return 0;
}