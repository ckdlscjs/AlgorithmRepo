#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1'000'005;
int T, N, M, val;
int arr[MaxN];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  for(int t = 0; t < T; t++)
  {
    std::memset(arr, 0, sizeof(arr));
    std::cin >> N;
    for(int i = 0; i < N; i++)
      std::cin >> arr[i];
    std::sort(arr, arr+N, std::less<>());
    std::cin >> M;
    for(int i = 0; i < M; i++)
    {
      std::cin >> val;
      int lo = -1, hi = N;
      while(lo + 1 < hi)
      {
        int mid = (lo + hi) / 2;
        if(val <= arr[mid]) hi = mid;
        else lo = mid;
      }
      std::cout << (arr[hi] == val ? 1 : 0) <<'\n';
    }
  }
  return 0;
}