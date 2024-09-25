#include <bits/stdc++.h>
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    bool notPrime[1000005];
    std::memset(notPrime, false, sizeof(notPrime));
    notPrime[0] = notPrime[1] = true;
    for(int i = 2; i <= std::sqrt(1000005); i++)
    {
        if(notPrime[i])
            continue;
        for(int j = 2; i * j <= 1000005; j++)
            notPrime[i * j] = true;
    }
    int n, input;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
      std::cin >> input;
      int cnt = 0;
      for(int i = 2; i <= input / 2; i++)
      {
        if(!notPrime[i] && !notPrime[input-i])
          cnt++;
      }
      std::cout << cnt <<'\n';
    }
    
    return 0;
}