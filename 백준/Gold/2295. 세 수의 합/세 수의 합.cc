#include <bits/stdc++.h>
long long int N, arr[1005];
std::vector<long long int> sums;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
    std::cin >> arr[i];
  for(int i = 0; i < N; i++)
    for(int j = i; j < N; j++)
      sums.push_back(arr[i] + arr[j]);
  std::sort(arr, arr+N);
  std::sort(sums.begin(), sums.end());
  for(int i = N-1; i >= 0; i--)
  {
    for(int j = 0; j <= i; j++)
    {
      int lo = -1, hi = sums.size();
      while(lo + 1 < hi)
      {
        int mid = (lo + hi) / 2;
        if(sums[mid] == arr[i] - arr[j])
        {
          std::cout << arr[i];
          return 0;
        }
        else if(sums[mid] > arr[i] - arr[j]) hi = mid;
        else lo = mid;
      }
    }
  }
  return 0;
}