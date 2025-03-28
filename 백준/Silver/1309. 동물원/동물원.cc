#include <bits/stdc++.h>
using namespace std;
int N, dp[100'005][3];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for(int n = 2; n <= N; n++)
    {
        dp[n][0] = (dp[n-1][0] + dp[n-1][1] + dp[n-1][2])%9901;
        dp[n][1] = (dp[n-1][0] + dp[n-1][2])%9901;
        dp[n][2] = (dp[n-1][0] + dp[n-1][1])%9901;
    }
    std::cout << (dp[N][0] + dp[N][1] + dp[N][2]) % 9901;
    return 0;
}
