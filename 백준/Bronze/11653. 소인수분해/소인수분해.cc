#include <bits/stdc++.h>
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    int divisor = 2;
    while(n != 1)
    {
      if(n % divisor)
      {
        divisor++;
        continue;
      }
      std::cout << divisor <<'\n';
      n /= divisor;
    }
    return 0;
}