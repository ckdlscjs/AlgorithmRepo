#include <bits/stdc++.h>
using namespace std;
long long int X, Y;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> X >> Y;
  long long int lo = -1, hi = 1'000'000'005;
  long long int Z = Y *100 / X;
  if(Z >= 99)
  {
    std::cout << -1;
    return 0;
  }
  while(lo + 1 < hi)
  {
    long long int mid = (lo + hi) / 2;
    if((Y+mid)*100 / (X+mid) > Z) hi = mid;
    else lo = mid;
  }
  
  std::cout <<hi;
  return 0;
}