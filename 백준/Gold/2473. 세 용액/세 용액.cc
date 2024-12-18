#include <bits/stdc++.h>
long long int N, arr[5'005], sum = 3'000'000'005, a, b, c;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++) std::cin >> arr[i];
  std::sort(arr, arr+N);
  for(int i = 0; i < N; i++)
  {
    for(int j = i+1; j < N; j++)
    {
      int lo = j, hi = N;
      while(lo + 1 < hi)
      {
        int mid = (lo + hi) / 2;
        long long int temp = arr[i] + arr[j] + arr[mid];
        if(std::abs(temp) < sum)
        {
          sum = std::abs(temp);
          a = arr[i];
          b = arr[j];
          c = arr[mid];
        }
        if(temp > 0) hi = mid;
        else lo = mid;
      }
    }
  }
  std::cout << a << ' ' << b << ' ' << c;
  return 0;
}