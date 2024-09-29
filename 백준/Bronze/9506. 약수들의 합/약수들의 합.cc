#include <bits/stdc++.h>
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    while(std::cin >> n && n != -1)
    {
      std::set<int> factors;
      int sum = 1;
      factors.insert(1);
      for(int i = 2; i <= std::sqrt(n); i++)
      {
        if(n%i == 0)
        {
          factors.insert(i);
          factors.insert(n/i);
          sum += i + n/i;
        }
      }
      std::cout << n << " ";
      if(sum == n)
      {
        std::cout << "= ";
        for(auto iter = factors.begin(); iter != std::prev(factors.end()); iter++)
        {
          std::cout <<*iter << " + ";
        }
        std::cout << *factors.rbegin();
      }
      else
        std::cout <<"is NOT perfect.";
      std::cout <<'\n';
    }
    return 0;
}