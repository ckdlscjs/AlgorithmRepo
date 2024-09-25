#include <bits/stdc++.h>
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  long long int a, b, mx, mn;
  std::cin >> a >> b;
  mx = std::max(a, b);
  mn = std::min(a, b);
  while(mx % mn)
  {
    int temp = mx % mn;
    mx = mn;
    mn = temp;
  }
  std::cout << a * b / mn;
 
  return 0;
}