#include <bits/stdc++.h>
int x, y, a, b;
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    while(std::cin >> a >> b)
    {
        x ^= a;
        y ^= b;
    }
    std::cout << x << ' ' << y;

    return 0;
}