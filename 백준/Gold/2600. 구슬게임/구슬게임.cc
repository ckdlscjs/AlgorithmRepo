#include <bits/stdc++.h>
using namespace std;
int b[3], dp[505][505];
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> b[0] >> b[1] >> b[2];
    std::sort(b, b+3);
    dp[0][0] = 1;
    for(int i = 0; i <= 500; i++)
    {
        for(int j = 0; j <= 500; j++)
        {
            if(i >= b[0] && dp[i-b[0]][j] == 1) dp[i][j] = 0;
            else if(i >= b[1] && dp[i-b[1]][j] == 1) dp[i][j] = 0;
            else if(i >= b[2] && dp[i-b[2]][j] == 1) dp[i][j] = 0;
            else if(j >= b[0] && dp[i][j-b[0]] == 1) dp[i][j] = 0;
            else if(j >= b[1] && dp[i][j-b[1]] == 1) dp[i][j] = 0;
            else if(j >= b[2] && dp[i][j-b[2]] == 1) dp[i][j] = 0;
            else dp[i][j] = 1;
            //std::cout << i << j << dp[i][j] << ' ';
        }
    }
    for(int m = 0; m < 5; m++)
    {
        int k1, k2;
        std::cin >>k1 >> k2;
        std::cout << (dp[k1][k2] ? 'B' : 'A') << '\n';
    }

    return 0;
}