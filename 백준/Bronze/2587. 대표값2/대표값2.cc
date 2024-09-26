#include <bits/stdc++.h>
int arr[1000005];
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int sum = 0;
  for(int i = 0; i < 5; i++)
  {
      std::cin >> arr[i];
      sum += arr[i];
  }
  std::sort(arr, arr+5, std::greater<>());
  std::cout << sum/5 << '\n' << arr[2];
  return 0;
}