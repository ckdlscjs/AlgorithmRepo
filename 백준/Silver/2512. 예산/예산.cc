#include <bits/stdc++.h>
int N, arr[10'005], M, sum, lo, hi;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> arr[i];
    hi = std::max(arr[i], hi);
  }
  std::cin >> M;
  hi++;
  while(lo + 1 < hi)
  {
    int mid = (lo + hi) / 2;
    sum = 0;
    for(int i = 0; i < N; i++)
      sum += (arr[i] >= mid ? mid : arr[i]);
    if(sum <= M) lo = mid;
    else hi = mid;
  }
  std::cout << lo;
  return 0;
}