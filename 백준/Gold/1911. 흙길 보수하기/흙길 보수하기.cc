#include <bits/stdc++.h>
using namespace std;
int n, l, LL, RR, res, cnt;
std::pair<int, int> water[10005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> l;
  for(int i = 0; i < n; i++)
    std::cin >> water[i].first >> water[i].second;
  std::sort(water, water+n, [](const std::pair<int, int>& a, const std::pair<int, int>& b)
  {
    return a.second < b.second;
  });
  for(int i = 0; i < n; i++)
  {
    if(RR < water[i].second)
    {
      LL = std::max(water[i].first, RR);
      RR = water[i].second - LL;
      cnt = (RR / l + (RR%l? 1 : 0));
      RR = cnt * l + LL;
      res += cnt;
    }
  }
  std::cout << res;
  return 0;
}