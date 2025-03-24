#include <bits/stdc++.h>
int N, dp[50'005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::fill_n(dp, 50'005, 4);
    for(int i = 1; i*i <= 50'000; i++) dp[i*i] = 1;
    for(int i = 1; i <= 50'000; i++)
    {
        for(int j = 1; i - j*j >= 0; j++)
            dp[i] = std::min(dp[i], dp[i - j*j] + 1);
    }
    std::cin >> N;
    std::cout << dp[N];
	return 0;
}