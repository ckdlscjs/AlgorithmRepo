#include <bits/stdc++.h>
int n;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  for(int i = 0; i < (n * 2) - 1; i++)
  {
    if(i < n)
    {
      for(int j = 0; j < i; j++) std::cout << " ";
      for(int j = 0; j < (n*2) - 2 * i - 1; j++) std::cout << "*";
    }
    else
    {
      for(int j = 0; j < (n * 2) - 2 - i; j++) std::cout << " ";
      for(int j = 0; j < (2 * i) - (n*2) + 3; j++) std::cout << "*";
    }
    std::cout << '\n';
  }
  return 0;
}