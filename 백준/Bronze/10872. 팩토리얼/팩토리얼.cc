#include <bits/stdc++.h>
long long int Factorial(int n)
{
  long long int res = 1;
  for(int i = 1; i <= n; i++)
    res *= i;
  return res;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  std::cout << Factorial(n);
  return 0;
}