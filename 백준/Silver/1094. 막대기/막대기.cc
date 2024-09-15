#include <bits/stdc++.h>
using namespace std;
int x;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> x;
  int cnt = 0;
  for(int i = 0; i <= 6; i ++)
  {
    if(x & 1 << i)
      cnt++;
  }
  std::cout << cnt;
  return 0;
}