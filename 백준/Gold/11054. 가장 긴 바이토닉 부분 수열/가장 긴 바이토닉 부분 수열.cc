#include <bits/stdc++.h>
int N, arr[1'005], dpij[1'005], dpji[1'005], res;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 0; n < N; n++) std::cin >> arr[n];
  std::fill_n(&dpij[0], 1'005, 1);
  std::fill_n(&dpji[0], 1'005, 1);
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < i; j++)
    {
      if(arr[j] < arr[i] && dpij[i] < dpij[j]+1)
        dpij[i] = dpij[j] + 1;
    }
  }
  for(int i = N - 1; i >= 0; i--)
  {
    for(int j = N - 1; j > i; j--)
    {
      if(arr[j] < arr[i] && dpji[i] < dpji[j]+1)
        dpji[i] = dpji[j] + 1;
    }
  }
  for(int i = 0; i < N; i++)
    res = std::max(res, dpij[i] + dpji[i] - 1);
  std::cout << res;
  return 0;
}