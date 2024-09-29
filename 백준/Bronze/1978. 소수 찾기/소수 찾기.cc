#include <bits/stdc++.h>
int n, ans, input;
bool NotPrime[1005];
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    NotPrime[0] = NotPrime[1] = true;
    for(int i = 2; i <= std::sqrt(1005); i++)
    {
      if(NotPrime[i])
        continue;
      for(int j = 2; j*i <= 1005; j++)
        NotPrime[j*i] = true;
    }
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
      std::cin >> input;
      ans += !NotPrime[input];
    }
    std::cout << ans;
    return 0;
}