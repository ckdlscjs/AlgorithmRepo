#include <bits/stdc++.h>

using namespace std;
int arr[1'000'005];
int n, m;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m;
  int lo = 0, hi = 0;
  for(int i = 0; i < n; i++)
  {
      std::cin >> arr[i];
      hi = std::max(hi, arr[i]);
  }
  hi += 1; 
  while(lo + 1 < hi)
  {
    int mid = (lo + hi) / 2;
    long long int sum = 0;
    for(int i = 0; i < n; i++)
      if(arr[i] > mid)
        sum += arr[i] - mid;
    if(m <= sum) lo = mid;
    else hi = mid;
  }
  std::cout << lo;
  return 0;
}