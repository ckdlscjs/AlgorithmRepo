#include <bits/stdc++.h>
using namespace std;
int N, K, W, V, dp[100'005];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> K;
    for(int n = 1; n <= N; n++)
    {
        std::cin >> W >> V;
        for(int k = K; k - W>= 0; k--)
        {
            dp[k] = std::max(dp[k], dp[k-W] + V);
        }
    }
    std::cout << dp[K];
    return 0;
}
