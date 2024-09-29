#include <bits/stdc++.h>
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int a, b;
    while(std::cin >> a >> b && a && b)
    {
      if(a > b && a % b == 0)
        std::cout << "multiple";
      else if(a < b && b % a == 0)
        std::cout << "factor";
      else
        std::cout << "neither";
      std::cout <<'\n';
    }
    
    return 0;
}