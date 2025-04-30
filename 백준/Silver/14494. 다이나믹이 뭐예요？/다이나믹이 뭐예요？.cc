#include <bits/stdc++.h>
using namespace std;
const int Mod = (int)1e9 + 7;
int N, M, dp[1'005][1'005];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> M;
    dp[0][0] = 1;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= Mod;
            dp[i][j] += dp[i][j-1];
            dp[i][j] %= Mod;
            dp[i][j] += dp[i-1][j-1];
            dp[i][j] %= Mod;
        }
    }
    std::cout << dp[N][M];
    return 0;
}
