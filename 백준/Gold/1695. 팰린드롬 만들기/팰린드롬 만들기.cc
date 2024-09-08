#include <bits/stdc++.h>
const int MaxN = 5005;
int arr[MaxN];
int dp[MaxN][MaxN];
int n;
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = i; j < n; j++)
        {
            if(i == j)
                dp[i][j] = 0;
            else if(arr[i] != arr[j])
                dp[i][j] = std::min(dp[i+1][j], dp[i][j-1]) + 1;
            else
                dp[i][j] = dp[i+1][j-1];
        }
    }
    std::cout << dp[0][n-1];
    return 0;
}