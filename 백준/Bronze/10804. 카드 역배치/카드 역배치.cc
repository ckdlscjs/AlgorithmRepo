#include <bits/stdc++.h>
int arr[25];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  for(int i = 1; i <= 20; i++)
    arr[i] = i;
  for(int i = 0; i < 10; i++)
  {
    int a, b;
    std::cin >> a >> b;
    std::reverse(arr + a, arr + 1 + b);
  }
  for(int i = 1; i <= 20; i++)
    std::cout << arr[i] << ' ';
  return 0;
}