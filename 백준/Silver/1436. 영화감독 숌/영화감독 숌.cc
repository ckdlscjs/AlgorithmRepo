#include <bits/stdc++.h>
using namespace std;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  int start = 666;
  while(n > 0)
  {
    std::string str = std::to_string(start);
    if(str.find("666") != std::string::npos)
      n--;
    start++;
  }
  std::cout << start - 1;
  return 0;
}