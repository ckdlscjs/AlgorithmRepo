#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::string str;
  std::cin >> str;
  for(int i = 0; i < str.size()/2; i++)
  {
    if(str[i] != str[str.size()-1-i])
    {
      std::cout << 0;
      return 0;
    }
  }
  std::cout << 1;
  return 0;
}