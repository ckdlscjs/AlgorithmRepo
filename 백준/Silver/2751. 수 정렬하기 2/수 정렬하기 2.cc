#include <bits/stdc++.h>
int arr[1000005];
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
 
  std::cin >> n;
  for(int i = 0; i < n; i++)
      std::cin >> arr[i];
  std::sort(arr, arr+n, std:: less<>());
  for(int i = 0; i < n; i++)
     std::cout << arr[i] << '\n';
  return 0;
}