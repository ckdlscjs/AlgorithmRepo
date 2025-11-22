/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
#define tlll std::tuple<long long, long long, long long>
const long long INF = LLONG_MAX;
long long N, M, K;
long long dp[22][10'002];
std::vector<std::pair<long long, long long>> graph[10'002];
std::priority_queue<tlll, std::vector<tlll>, std::greater<tlll>> pq;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::fill_n(&dp[0][0], 22 * 10'002, INF);
    std::cin >> N >> M >> K;
    for(int m = 0; m < M; m++)
    {
        long long u, v, w;
        std::cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dp[0][1] = 0;
    pq.push({dp[0][1], 1, 0});
    while(pq.size())
    {
        long long cw = std::get<0>(pq.top());
        long long cu = std::get<1>(pq.top());
        long long ck = std::get<2>(pq.top());
        pq.pop();
        if(dp[ck][cu] < cw) continue;
        for(const auto& iter : graph[cu])
        {
            long long v = iter.first;
            long long w = iter.second;
            if(ck <= K && dp[ck][cu] + w < dp[ck][v])
            {
                dp[ck][v] = dp[ck][cu] + w;
                pq.push({dp[ck][v], v, ck});
            }
            if(ck + 1 <= K && dp[ck][cu] < dp[ck+1][v])
            {
                dp[ck+1][v] = dp[ck][cu];
                pq.push({dp[ck+1][v], v, ck+1});
            }
        }
    }
    long long result = INF;
    for(int k = 0; k <= K; k++)
        result = std::min(result, dp[k][N]);
    std::cout << result;
    return 0;
}
