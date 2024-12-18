#include <bits/stdc++.h>
int N, C, arr[200'005];
bool Check(int mid)
{
  int cnt = 1;
  int cur = arr[0] + mid-1;
  for(int i = 1; i < N; i++)
  {
    if(arr[i] <= cur) continue;
    cur = arr[i] + mid-1;
    cnt++;
  }
  return cnt >= C;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> C;
  for(int i = 0; i < N; i++) std::cin >> arr[i];
  std::sort(arr, arr+N);
  int lo = 1, hi = 1'000'000'005;
  while(lo + 1 < hi)
  {
    int mid = (lo + hi) / 2;
    int cnt = 1;
    //std::cout << lo << ' ' << hi << ' '  << cnt << '\n';
    if(Check(mid)) lo = mid;
    else hi = mid;
  }
  std::cout << lo;
  return 0;
}