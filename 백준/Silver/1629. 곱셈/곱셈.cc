#include <bits/stdc++.h>
using namespace std;
long long int a, b, c;
long long int check(int B)
{
  if(B <= 1)
    return a % c;
  long long int temp = check(B/2);
  if(B%2)
  {
    return temp % c * temp % c * a %c;
  }
  else
    return temp %c * temp % c;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> a >> b >> c;
  std::cout << check(b);
  return 0;
}