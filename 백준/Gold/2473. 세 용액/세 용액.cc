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
  for(int i = 0; i < N-2; i++)
  {
    int l = i+1, r = N-1;
    while(l < r)
    {
      long long int temp = arr[i] + arr[l] + arr[r];
      if(std::abs(temp) < sum)
      {
        sum = std::abs(temp);
        a = arr[i];
        b = arr[l];
        c = arr[r];
      }
      if(temp > 0) r--;
      else l++;
    }
  }
  std::cout << a << ' ' << b << ' ' << c;
  return 0;
}