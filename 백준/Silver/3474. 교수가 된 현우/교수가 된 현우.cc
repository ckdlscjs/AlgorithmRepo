#include <bits/stdc++.h>
using namespace std;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  for(int i = 0; i < n; i++)
  {
    int num, cnt5 = 0;
    std::cin >> num;
    int f = 5;
    while(num >= f)
    {
      cnt5 += num/f;
      f *= 5;
    }
  std::cout << cnt5 <<'\n';
  }
  return 0;
}