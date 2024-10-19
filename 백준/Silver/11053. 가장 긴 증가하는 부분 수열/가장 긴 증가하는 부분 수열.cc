#include <bits/stdc++.h>
using namespace std;
int N, len, arr[1'005], lis[1'005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
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
        int mid = (lo + hi) /2;
        if(arr[i] <= lis[mid]) hi = mid;
        else lo = mid;
      }
      lis[hi] = arr[i];
    }
  }
  std::cout << len << '\n';
  return 0;
}