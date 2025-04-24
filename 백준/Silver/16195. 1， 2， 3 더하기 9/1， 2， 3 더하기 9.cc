#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1'000'000'009;
long long T, N, M, dp[1'005][1'005];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 2;
    dp[3][3] = 1;
    for(int i = 4; i <= 1'000; i++)
    {
        for(int j = 2; j <= i; j++)
        {
            dp[i][j] = (dp[i-1][j-1] % Mod + dp[i-2][j-1] % Mod + dp[i-3][j-1] % Mod) % Mod;
        }
    }
    std::cin >> T;
    for(int t = 0; t < T; t++)
    {
        std::cin >> N >> M;
        long long ans = 0;
        for(int m = 1; m <= M; m++)
        {
            ans += dp[N][m];
            ans %= Mod;
        }
        std::cout << ans << '\n';
    }
    return 0;
}