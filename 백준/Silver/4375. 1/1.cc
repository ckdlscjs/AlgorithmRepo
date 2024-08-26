#include <bits/stdc++.h>
using namespace std;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  while(std::cin >> n)
  {
    int cnt = 1;
    long long int num = 1;
    while(num % n != 0)
    {
      num *= 10;
      num += 1;
      cnt++;
      num %= n;
    }
    std::cout << cnt <<'\n';
  }
  return 0;
}