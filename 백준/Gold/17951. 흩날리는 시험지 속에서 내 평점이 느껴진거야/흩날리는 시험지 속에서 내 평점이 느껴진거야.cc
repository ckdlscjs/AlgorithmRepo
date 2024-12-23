#include <bits/stdc++.h>
int N, K, arr[100'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> K;
  for(int i = 0; i < N; i++) std::cin >> arr[i];
  int lo = 0, hi = 2'000'005;
  while(lo + 1 < hi)
  {
    int mid = (lo + hi) / 2;
    int cnt = 0, sum = 0;
    for(int i = 0; i < N; i++)
    {
      sum += arr[i];
      if(sum >= mid)
      {
        cnt++;
        sum = 0;
      }
    }
    if(cnt >= K) lo = mid;
    else hi = mid;
  }
  std::cout << lo;
  return 0;
}