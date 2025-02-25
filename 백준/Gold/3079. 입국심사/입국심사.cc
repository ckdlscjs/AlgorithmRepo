#include <bits/stdc++.h>
#define ulli unsigned long long int
ulli N, M, arr[100'005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int n = 0; n < N; n++) std::cin >> arr[n];
  ulli lo = 0, hi = 1e19 + 5;
  while(lo + 1 < hi)
  {
    ulli mid = (lo + hi) / 2;
    ulli cnt = 0;
    for(int n = 0; n < N; n++) cnt += mid/arr[n];
    if(cnt >= M) hi = mid;
    else lo = mid;
  }
  if(N >= M)
    hi = std::min(hi, arr[N-1]);
  std::cout << hi;
  return 0;
}