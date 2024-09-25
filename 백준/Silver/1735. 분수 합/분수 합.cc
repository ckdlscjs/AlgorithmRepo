#include <bits/stdc++.h>
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int ua, da, ub, db;
  std::cin >> ua >> da >> ub >> db;
  ua = ua*db + ub * da;
  da = da*db;
  ub = std::max(ua, da);
  db = std::min(ua, da);
  while(ub % db)
  {
    int temp = ub % db;
    ub = db;
    db = temp;
  }
  std::cout << ua / db << ' ' <<da / db;
 
  return 0;
}