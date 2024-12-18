#include <bits/stdc++.h>
int N, val, len, lis[1'000'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> val;
    if(i == 0 || lis[len-1] < val)
    {
      lis[len++] = val;
    }
    else
    {
      int lo = -1, hi = len;
      while(lo + 1 < hi)
      {
        int mid = (lo + hi) / 2;
        if(val <= lis[mid]) hi = mid;
        else lo = mid;
      }
      lis[hi] = val;
    }
  }
  std::cout << len;
  return 0;
}