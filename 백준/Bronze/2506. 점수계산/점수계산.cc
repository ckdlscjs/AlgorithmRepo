#include <bits/stdc++.h>
int N, input, carry, sum;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 0; n < N; n++)
  {
    std::cin >> input;
    sum += input;
    if(input)
    {
      sum += carry;
      carry += 1;
    }
    else
      carry = 0;
  }
  std::cout << sum;
  return 0;
}