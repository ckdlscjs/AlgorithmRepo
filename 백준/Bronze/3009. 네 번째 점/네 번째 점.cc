#include <bits/stdc++.h>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::unordered_map<int, int> x;
    std::unordered_map<int, int> y;
    for(int i = 0; i < 3; i++)
    {
        int a, b;
        std::cin >> a >> b;
        x[a]++;
        y[b]++;
    }
    for(const auto& iter: x)
        if(iter.second == 1)
            std::cout << iter.first << ' ';
    for(const auto& iter: y)
        if(iter.second == 1)
            std::cout << iter.first;
    return 0;
}