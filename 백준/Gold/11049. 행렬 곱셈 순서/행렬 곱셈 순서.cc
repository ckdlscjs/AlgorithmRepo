#include <bits/stdc++.h>
using namespace std;
int N, cnt, dp[505][505];
std::vector<std::pair<int, int>> arr;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    arr.resize(N+1);
    for(int i = 1; i <= N; i++)  std::cin >> arr[i].first >> arr[i].second;
    
    for(int i = 1; i < N; i++)
    {
        for(int j = 1; i + j <= N; j++)
        {
            dp[j][i+j] = INT_MAX;
            for(int k = j; k < i + j; k++)
            {
                dp[j][i+j] = std::min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + arr[j].first * arr[k].second * arr[i+j].second);
            }
        }
    }
    std::cout << dp[1][N];
    return 0;
}