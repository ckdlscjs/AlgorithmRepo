#include <bits/stdc++.h>
int N, arr[100'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++) std::cin >> arr[i];
  std::sort(arr, arr+N);
  int l = 0, r = N-1, res = INT_MAX;
  std::pair<int, int> result;
  while(l < r)
  {
    int sum = arr[l] + arr[r];
    if(std::abs(sum) < res)
    {
      res = std::abs(sum);
      result.first = arr[l];
      result.second = arr[r];
    }
    if(sum > 0)
      r--;
    else
      l++;
  }
  std::cout << result.first << ' ' << result.second;
  return 0;
}