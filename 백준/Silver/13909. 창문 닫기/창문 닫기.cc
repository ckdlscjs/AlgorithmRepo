#include <bits/stdc++.h>
int n;
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    int ans = 0;
    for(int i = 1; i * i <= n; i++)
        ans++;
    std::cout << ans;
    return 0;
}