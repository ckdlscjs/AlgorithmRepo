#include <bits/stdc++.h>
int arr[1000005];
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n, k;
  std::cin >> n >> k;
  for(int i = 0; i < n; i++)
      std::cin >> arr[i];
  std::sort(arr, arr+n, std::greater<>());
  std::cout << arr[k-1];
  return 0;
}