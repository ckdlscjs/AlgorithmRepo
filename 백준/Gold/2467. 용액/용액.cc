#include <bits/stdc++.h>
int N;
int arr[100'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
    std::cin >> arr[i];
  std::pair<int, int> res;
  int ans = INT_MAX;
  for(int i = 0; i < N; i++)
  {
    int lo = i, hi = N;
    while(lo + 1 < hi)
    {
      int mid = (lo + hi) / 2;
      int sum = arr[i] + arr[mid];
      if(std::abs(sum) < ans)
      {
        ans = std::abs(sum);
        res.first = arr[i];
        res.second = arr[mid];
        if(ans == 0)
          break;
      }
      if(sum > 0) hi = mid;
      else lo = mid;
    }
    if(ans == 0)
      break;
  }
  std::cout << res.first << ' ' << res.second;
  return 0;
}