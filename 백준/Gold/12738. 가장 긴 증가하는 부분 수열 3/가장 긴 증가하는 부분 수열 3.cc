#include <bits/stdc++.h>
int N, arr[1'000'005], len, lis[1'000'005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 0; n < N; n++)
  {
    std::cin >> arr[n];
    if(n == 0 || lis[len-1] < arr[n])
    {
      lis[len++] = arr[n];
    }
    else
    {
      int lo = -1, hi = len;
      while(lo + 1 < hi)
      {
        int mid = (lo + hi) / 2;
        if(arr[n] <= lis[mid]) hi = mid;
        else lo = mid;
      }
      lis[hi] = arr[n];
    }
  }
  std::cout << len;
  return 0;
}