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
    for(int j = 0; j < N - i - 1; j++) std::cout << ' '; 
    for(int j = 0; j <= i; j++) std::cout << '*';
    for(int j = 0; j <= i - 1; j++) std::cout << '*';
    std::cout << '\n';
  }
  return 0;
}