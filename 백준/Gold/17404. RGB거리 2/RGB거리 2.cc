#include <bits/stdc++.h>
using namespace std;
int N, dp[1'005][3][3], r,g,b;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    std::fill_n(&dp[0][0][0], 1005*3*3, 1000*1000*3);
    for(int n = 0; n < N; n++)
    {
        std::cin >> r >> g >> b;
        if(n == 0)
        {
            dp[0][0][0] = r;
            dp[0][1][1] = g;
            dp[0][2][2] = b;
        }
        else if(0 < n && n < N-1)
        {
            for(int j = 0; j < 3; j++)
            {
                dp[n][j][0] = std::min(dp[n-1][j][1], dp[n-1][j][2]) + r;
                dp[n][j][1] = std::min(dp[n-1][j][0], dp[n-1][j][2]) + g;
                dp[n][j][2] = std::min(dp[n-1][j][0], dp[n-1][j][1]) + b;
            }
        }
        else if(n >= N-1)
        {
            dp[n][1][0] = std::min(dp[n-1][1][1], dp[n-1][1][2]) + r;
            dp[n][2][0] = std::min(dp[n-1][2][1], dp[n-1][2][2]) + r;
            
            dp[n][0][1] = std::min(dp[n-1][0][0], dp[n-1][0][2]) + g;
            dp[n][2][1] = std::min(dp[n-1][2][0], dp[n-1][2][2]) + g;
            
            dp[n][0][2] = std::min(dp[n-1][0][0], dp[n-1][0][1]) + b;
            dp[n][1][2] = std::min(dp[n-1][1][0], dp[n-1][1][1]) + b;
        }
    }
    std::cout << std::min({dp[N-1][1][0], dp[N-1][2][0], dp[N-1][0][1], dp[N-1][2][1], dp[N-1][0][2], dp[N-1][1][2]});
    return 0;
}
