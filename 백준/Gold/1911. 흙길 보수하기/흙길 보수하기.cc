#include <bits/stdc++.h>
using namespace std;
int n, l;
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
  int left = water[0].first;
  int right = (water[0].second - water[0].first);
  int res = (right / l + (right%l? 1 : 0));
  right = res * l + left;
  for(int i = 1; i < n; i++)
  {
    if(right < water[i].second)
    {
      left = std::max(water[i].first, right);
      right = water[i].second - left;
      int cnt = (right / l + (right%l? 1 : 0));
      right = cnt * l + left;
      res += cnt;
    }
  }
  std::cout << res;
  return 0;
}