#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int sum = 0, val = 0, minval = 105;
    for(int i = 0; i < 7; i++)
    {
      std::cin >> val;
      sum += val % 2 ? val : 0;
      minval = std::min({minval, val%2 ? val : 105});
    }
    std::cout << (sum ? sum : -1) << '\n';
    if(minval < 100)
      std::cout << minval;
    return 0;
}