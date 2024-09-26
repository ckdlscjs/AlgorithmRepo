#include <bits/stdc++.h>
int a, b, c, d, e, f;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> a >> b >> c >> d >> e >> f;
  std::cout << (c*e-b*f)/(a*e - b*d) << ' ' <<(d*c-a*f)/(b*d-a*e);
  return 0;
}