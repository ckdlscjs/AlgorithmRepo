/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
#define tlll std::tuple<long long, long long, long long>
const long long INF = 987654321;
long long N, A, B, M, costs[55], earns[55];
std::vector<tlll> edges;
std::vector<int> graph[55];
std::queue<int> q;
bool visited[55];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> N >> A >> B >> M;
    std::fill_n(&costs[0], 55, -INF);
    for(int m = 0; m < M; m++)
    {
        long long u, v, w;
        std::cin >> u >> v >> w;
        edges.push_back({u, v, -w});
        graph[v].push_back(u);
    }
    for(int n = 0; n < N; n++)
        std::cin >> earns[n];
        
    visited[B] = true;
    q.push(B);
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        for(const auto& iter : graph[cur])
        {
            if(visited[iter]) continue;
            visited[iter] = true;
            q.push(iter);
        }
    }
    
    costs[A] = earns[A];
    for(int i = 0; i < N; i++)
    {
        for(const auto& iter : edges)
        {
            long long u = std::get<0>(iter);
            long long v = std::get<1>(iter);
            long long w = std::get<2>(iter);
            if(costs[u] > -INF && costs[u] + w + earns[v] > costs[v])
            {
                if(i >= N-1 && visited[v])
                {
                    std::cout << "Gee";
                    return 0;
                }
                costs[v] = costs[u] + w + earns[v];
            }
        }
    }
    if(costs[B] <= -INF)
    {
        std::cout << "gg";
        return 0;
    }
    
    std::cout << costs[B];
    return 0;
}
