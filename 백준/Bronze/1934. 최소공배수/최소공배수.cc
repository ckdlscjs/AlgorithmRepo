#include <bits/stdc++.h>
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  for(int i = 0; i < n; i++)
  {
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
    std::cout << a * b / mn << '\n';
  }
  
 
  return 0;
}