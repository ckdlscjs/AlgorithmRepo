#include <bits/stdc++.h>
int n;
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    std::set<int> divisors;
    for(int i = 2; i <= std::sqrt(n); i++)
    {
      if(n%i == 0)
      {
        divisors.insert(i);
        divisors.insert(n/i);
      }
    }
    divisors.insert(n);
    std::set<int>::iterator iter = divisors.begin();
    while(n != 1)
    {
      if(n % *iter)
      {
        iter++;
        continue;
      }
      std::cout <<*iter <<'\n';
      n /= *iter;
    }
    return 0;
}