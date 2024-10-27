#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int A;
    std::cin >> A;
    std::cout << (A >= 90 ? "A" : A >= 80 ? "B" : A >= 70 ? "C" : A >= 60 ? "D" : "F");
    return 0;
}