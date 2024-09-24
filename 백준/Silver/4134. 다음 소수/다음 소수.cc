#include <bits/stdc++.h>
long long int n, input;
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
      std::cin >> input;
      while(input >= 2)
      {
          bool notPrime = false;
          for(int i = 2; i <= std::sqrt(input); i++)
          {
            if(input % i == 0)
            {
              notPrime = true;
              break;
            }
          }
          if(!notPrime)
            break;
          input++;
      }  
      std::cout << (input < 2 ? 2 : input) <<'\n';
    }
    return 0;
}