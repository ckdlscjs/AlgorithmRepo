#include <bits/stdc++.h>
int N, C, arr[200'005];
void Check(int& cnt, int mid)
{
  int cur = arr[0] + mid-1;
  for(int i = 1; i < N; i++)
  {
    if(arr[i] <= cur) continue;
    cur = arr[i] + mid-1;
    cnt++;
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> C;
  for(int i = 0; i < N; i++) std::cin >> arr[i];
  std::sort(arr, arr+N);
  int lo = 0, hi = 1'000'000'005;
  while(lo + 1 < hi)
  {
    int mid = (lo + hi) / 2;
    int cnt = 1;
    Check(cnt, mid);
    //std::cout << lo << ' ' << hi << ' '  << cnt << '\n';
    if(cnt == C) lo = mid;
    else if(cnt > C) lo = mid;
    else hi = mid;
  }
  std::cout << lo;
  return 0;
}