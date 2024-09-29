#include <bits/stdc++.h>
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int a, b, c;
    std::cin >> a >> b >> c;
    if(((a|b)|c) == 60)
        std::cout <<"Equilateral";
    else if(a+b+c != 180)
        std::cout <<"Error";
    else if(a+b+c == 180 && a != b && b != c && a != c)
        std::cout <<"Scalene";
    else
        std::cout <<"Isosceles";
    return 0;
}