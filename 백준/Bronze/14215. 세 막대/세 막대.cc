#include <bits/stdc++.h>
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int a, b, c;
    std::cin >> a >> b >> c;
    int large = std::max({a, b, c});
    std::cout << ((large*2 < a+b+c) ? a + b + c : (a + b + c)*2 - large*2 - 1);
    return 0;
}