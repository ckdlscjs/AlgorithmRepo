#include <bits/stdc++.h>
using namespace std;
int n, res = INT_MIN;
int cur, pre;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  std::cin >> n;
  for(int i = 0; i < n; i++)
  {
    std::cin >> cur;
    pre += cur;
    res = std::max(res, pre);
    pre = std::max(pre, 0);
  }
  std::cout << res;
  return 0;
}