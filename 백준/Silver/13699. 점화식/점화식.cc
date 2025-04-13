#include <bits/stdc++.h>
using namespace std;
long long N, dp[40];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    dp[0] = 1;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    std::cout << dp[N];
    return 0;
}
