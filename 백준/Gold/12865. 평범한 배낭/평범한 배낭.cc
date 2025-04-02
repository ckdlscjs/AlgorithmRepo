#include <bits/stdc++.h>
using namespace std;
int N, K, W, V, dp[105][100'005];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> K;
    for(int n = 1; n <= N; n++)
    {
        std::cin >> W >> V;
        for(int k = K; k >= 0; k--)
        {
            if(k-W < 0) dp[n][k] = dp[n-1][k];
            else dp[n][k] = std::max(dp[n-1][k], dp[n-1][k-W] + V);
        }
    }
    std::cout << dp[N][K];
    return 0;
}
