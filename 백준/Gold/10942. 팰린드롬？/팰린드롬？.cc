#include <bits/stdc++.h>
using namespace std;
int N, M, arr[2'005], dp[2'005][2'005];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++) std::cin >> arr[n];
    for(int i = N-1; i >= 0; i--)
    {
        for(int j = i; j < N; j++)
        {
            if(i == j) dp[i][j] = 1;
            else if(arr[i] == arr[j]) dp[i][j] = dp[i+1][j-1] + 2;
            else dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
        }
    }
    /*
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            std::cout << dp[i][j] << ' ';
        std::cout << '\n';
    }
    */
    std::cin >> M;
    for(int m = 0; m < M; m++)
    {
        int i, j;
        std::cin >> i >> j;
        std::cout << (dp[i-1][j-1] == j - i + 1 ? 1 : 0) << '\n';
    }
    return 0;
}
