#include <bits/stdc++.h>
int n, len;
int arr[40'005];
int lis[40'005];
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  for(int i = 0; i < n; i++)
  {
    std::cin >> arr[i];
    if(i == 0 || lis[len-1] < arr[i])
    {
      lis[len++] = arr[i];
    }
    else
    {
      int lo = -1, hi = len;
      while(lo + 1 < hi)
      {
        int mid = (lo + hi) / 2;
        if(arr[i] <= lis[mid]) hi = mid;
        else lo = mid;
      }
      lis[hi] = arr[i];
    }
  }
  std::cout << len;
  return 0;
}