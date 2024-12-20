#include <bits/stdc++.h>
long long int N, K;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> K;
  long long int lo = 0, hi = 1'000'000'005;
  while(lo + 1 < hi)
  {
    long long int mid = (lo + hi) / 2;
    long long int cnt = 0;
    for(int i = 1; i <= N; i++)
      cnt += std::min(N, mid / i);
    if(cnt >= K) hi = mid;
    else lo = mid;
  }
  std::cout << hi;
  return 0;
}