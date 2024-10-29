#include <bits/stdc++.h>
int N;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
  }
  return 0;
}