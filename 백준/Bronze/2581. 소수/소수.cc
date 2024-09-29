#include <bits/stdc++.h>
int m, n, ans = 20000, sum;
bool NotPrime[10005];
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> m >> n;
    NotPrime[0] = NotPrime[1] = true;
    for(int i = 2; i <= std::sqrt(10005); i++)
    {
      if(NotPrime[i])
        continue;
      for(int j = 2; j*i <= 10005; j++)
        NotPrime[j*i] = true;
    }
    for(int i = n; i >= m; i--)
    {
      if(!NotPrime[i])
      {
        sum += i;
        ans = i;
      }
    }
    if(sum == 0)
      std::cout << -1;
    else
      std::cout << sum << '\n' << ans;
    return 0;
}