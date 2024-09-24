#include <bits/stdc++.h>
int n;
bool notPrime[300000];
int primeCount[300000];
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    notPrime[0] = notPrime[1] = true;
    for(int i = 2; i <= std::sqrt(300000); i++)
    {
      if(notPrime[i])
        continue;
      for(int j = i*2; j <= 300000; j += i)
        notPrime[j] = true;
    }
    
    for(int i = 1; i <= 300000; i++)
    {
      primeCount[i] = notPrime[i] ? primeCount[i-1] : primeCount[i-1] + 1;
    }
    while(std::cin >> n && n)
    {
      std::cout << primeCount[n*2] - primeCount[n] <<'\n';
    }
  
    return 0;
}