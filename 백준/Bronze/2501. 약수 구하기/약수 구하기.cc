#include <bits/stdc++.h>
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, k, i;
    std::cin >> n >> k;
    int cnt = 0;
    for(i = 1; i <= n; i++)
    {
      if(n % i == 0)
        cnt++;
      if(cnt == k)
        break;
    }
    std::cout << (cnt == k ? i : 0);
    return 0;
}