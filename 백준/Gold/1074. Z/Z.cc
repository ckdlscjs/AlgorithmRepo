#include <bits/stdc++.h>
using namespace std;
int N, r, c, res;
void Check(int n, int y, int x)
{
  if(n <= 0)
  {
    if(y == r && x == c)
      std::cout << res;
    res++;
    return;
  }
  if(y <= r && r < y + (1 << n) && x <= c && c < x + (1 << n))
  {
    Check(n-1, y, x);
    Check(n-1, y, x + (1<<n-1));
    Check(n-1, y + (1 <<n-1), x);
    Check(n-1, y + (1 <<n-1), x + (1<<n-1));
  }
  else
  {
    res += (1 << n) * (1 << n);
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> r >> c;
  Check(N, 0, 0);
  return 0;
}