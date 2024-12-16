#include <bits/stdc++.h>
int N, M, val, arr[500'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++) std::cin >> arr[i];
  std::sort(arr, arr+N);
  std::cin >> M;
  for(int i = 0; i < M; i++)
  {
    std::cin >> val;
    int lo = -1, hi = N;
    while(lo + 1 < hi)
    {
      int mid = (lo + hi) / 2;
      if(arr[mid] <= val) lo = mid;
      else hi = mid;
    }
    std::cout << (arr[lo] == val ? 1 : 0) << ' ';
  }
  return 0;
}