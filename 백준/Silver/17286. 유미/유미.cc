#include <bits/stdc++.h>
const int INF = 987654321;
std::pair<int, int> arr[4];
double costs[4][4];
int res = 987654321;
void Check(int cur, double sum, int mask)
{
  if(mask == (1 << 4) - 1)
  {
    res = std::min(res, (int)sum);
  }
  else
  {
    for(int i = 1; i < 4; i++)
    {
      if(mask & 1 << i) continue;
      Check(i, sum + costs[cur][i], mask | 1 << i);
    }
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  for(int i = 0; i < 4; i++) std::cin >> arr[i].first >> arr[i].second;
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      costs[i][j] = std::sqrt((arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) + (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second));
    }
  }
  Check(0, 0, 1);
  std::cout << res;
  return 0;
}