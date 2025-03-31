#include <bits/stdc++.h>
using namespace std;
const int INF = 52;
int N, a, b, dp[52][52];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    std::fill_n(&dp[0][0], 52*52, INF);
    for(int i = 1; i <= N; i++) dp[i][i] = 0;
    while(std::cin >> a >> b)
    {
        if(a == -1 && b == -1) break;
        dp[a][b] = 1;
        dp[b][a] = 1;
    }
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    std::vector<int> results[52];
    for(int i = 1; i <= N; i++) results[*std::max_element(dp[i]+1, dp[i] + 1 + N)].push_back(i);
    for(int i = 1; i <= 52; i++)
    {
        if(results[i].empty()) continue;
        std::cout << i << ' ' << results[i].size() << '\n';
        for(const auto& iter : results[i])
            std::cout << iter << ' ';
        return 0;
    }
    return 0;
}
