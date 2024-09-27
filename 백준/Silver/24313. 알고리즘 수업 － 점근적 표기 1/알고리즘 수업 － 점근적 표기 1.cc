#include <bits/stdc++.h>
int a1, a0, c, n;
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> a1 >> a0 >> c >> n;
    std::cout << (a1*n + a0 <= c*n  && a1 <= c? 1 : 0);
    return 0;
}