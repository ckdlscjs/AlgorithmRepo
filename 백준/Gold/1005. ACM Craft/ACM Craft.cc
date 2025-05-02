#include <bits/stdc++.h>
using namespace std;
int T, N, K, D[1'005], indegree[1'005], dp[1'005], X, Y, W;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> T;
    for(int t = 0; t < T; t++)
    {
        std::cin >> N >> K;
        std::memset(D, 0, sizeof(D));
        std::memset(indegree, 0, sizeof(indegree));
        std::memset(dp, 0, sizeof(dp));
        std::vector<int> graph[1'005];
        for(int n = 1; n <= N; n++)
        {
            std::cin >> D[n];
            dp[n] = D[n];
        }
            
        for(int k = 0; k < K; k++)
        {
            std::cin >> X >> Y;
            graph[X].push_back(Y);
            indegree[Y]++;
        }
        std::cin >> W;
        
        std::queue<int> q;
        for(int n = 1; n <= N; n++)
            if(indegree[n] == 0)
                q.push(n);
        for(int n = 1; n <= N; n++)
        {
            int cur = q.front(); q.pop();
            for(const auto& iter : graph[cur])
            {
                dp[iter] = std::max(dp[iter], dp[cur] + D[iter]);
                indegree[iter]--;
                if(indegree[iter] <= 0)
                    q.push(iter);
            }
        }
        std::cout << dp[W] << '\n';
    }
    return 0;
}
