#include <bits/stdc++.h>
long long int N, C, arr[5'005];

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> C;
  for(int n = 0; n < N; n++) std::cin >> arr[n];
  std::sort(arr, arr+N, std::less<>());
  for(int i = 0; i < N; i++)
  {
    if(arr[i] == C)
    {
      std::cout << 1;
      return 0;
    }
    for(int j = i + 1; j < N; j++)
    {
      int lo = j, hi = N;
      while(lo + 1 < hi)
      {
        int mid = (lo + hi) / 2;
        if(arr[i] + arr[j] + arr[mid] >= C) hi = mid;
        else lo = mid;
      }
      if(arr[i] + arr[j] + arr[hi] == C || arr[i] + arr[j] == C)
      {
        std::cout << 1;
        return 0;
      }
    }
  }
  std::cout << 0;
  return 0;
}