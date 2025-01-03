#include <bits/stdc++.h>
int N, dp[1005];
int main(void)
{
    std::cin >> N;
    dp[2] = 1;
    for(int i = 4; i <= N; i++)
    {
        if(dp[i-1] == 1|| dp[i-3] == 1) dp[i] = 0;
        else dp[i] = 1;
    }
    std::cout << (dp[N] == 0 ? "SK" : "CY");
    return 0;
}