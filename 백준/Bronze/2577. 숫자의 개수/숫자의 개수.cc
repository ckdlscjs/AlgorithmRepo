#include <bits/stdc++.h>
int arr[10];
int A, B, C;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> A >> B >> C;
  A *= B * C;
  while(A)
  {
    arr[A%10]++;
    A/=10;
  }
  for(const auto& iter : arr)
    std::cout << iter << '\n';
  return 0;
}