#include <bits/stdc++.h>
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int a, b, c;
    while(std::cin >> a >> b >> c && a && b && c)
    {
      int large = std::max({a, b, c});
      if(large*2 >= a + b + c)
        std::cout <<"Invalid";
      else if(a == b && b == c && c == a)
        std::cout <<"Equilateral";
      else if(a != b && b != c && c != a)
        std::cout <<"Scalene";
      else
        std::cout <<"Isosceles";
      std::cout <<'\n';
    }
    
    return 0;
}