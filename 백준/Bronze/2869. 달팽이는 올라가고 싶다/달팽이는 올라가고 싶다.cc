#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int a, b, v;
    std::cin >> a >> b >> v;
    std::cout << ((v - b) % (a - b) ? (v-b)/(a-b) + 1 : (v-b)/(a-b));
    return 0;
}