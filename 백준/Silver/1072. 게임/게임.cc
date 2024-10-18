#include <bits/stdc++.h>
using namespace std;
long long int X, Y;
const int maxHi = 1'000'000'005;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> X >> Y;
  long long int lo = 0, hi = maxHi;
  long long int Z = Y *100 / X;
  while(lo + 1 < hi)
  {
    long long int mid = (lo + hi) / 2;
    if((Y+mid)*100 / (X+mid) > Z) hi = mid;
    else lo = mid;
  }
  
  std::cout << (hi == maxHi ? -1 : hi);
  return 0;
}