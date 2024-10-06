#include <bits/stdc++.h>
using namespace std;
int arr[25][25];
int n;
int res = 987654321;
void check(int cnt, int idx, int mask)
{
  if(cnt == n/2)
  {
    std::vector<int> start;
    std::vector<int> link;
    for(int i = 0; i < n; i++)
    {
      if(mask & 1 << i)
        start.push_back(i);
      else
        link.push_back(i);
    }
    int sum_start = 0;
    int sum_link = 0;
    for(int i = 0; i < start.size(); i++)
      for(int j = i+1; j < start.size(); j++)
        sum_start += arr[start[i]][start[j]] + arr[start[j]][start[i]];
     for(int i = 0; i < link.size(); i++)
      for(int j = i+1; j < link.size(); j++)
        sum_link += arr[link[i]][link[j]] + arr[link[j]][link[i]];
    res = std::min(res, std::abs(sum_start - sum_link));
    return;
  }
  if(cnt > n / 2)
    return;
  if(idx >= n)
    return;
  check(cnt, idx+1, mask);
  check(cnt+1, idx+1, mask | 1 << idx);
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      std::cin >> arr[i][j];
  check(0, 0, 0);
  std::cout << res;
  return 0;
}