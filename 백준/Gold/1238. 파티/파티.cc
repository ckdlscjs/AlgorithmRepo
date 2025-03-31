#include <bits/stdc++.h>
using namespace std;
using pii = std::pair<int, int>;
const int INF = 987654321;
int N, M, X, u, v, w, res;
std::vector<pii> UV[1'005];
std::vector<pii> VU[1'005];
void Dijkstra(const std::vector<pii>* graph, std::vector<int>& costs)
{
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    costs[X] = 0;
    pq.push({0, X});
    while(pq.size())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(costs[u] < w) continue;
        for(const auto& iter : graph[u])
        {
            if(costs[u] + iter.second > costs[iter.first]) continue;
            costs[iter.first] = costs[u] + iter.second;
            pq.push({costs[iter.first], iter.first});
        }
    }
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> M >> X;
    for(int m = 0; m < M; m++)
    {
        std::cin >> u >> v >> w;
        UV[u].push_back({v, w});
        VU[v].push_back({u, w});
    }
    std::vector<int> costs_uv(N+1, INF);
    std::vector<int> costs_vu(N+1, INF);
    Dijkstra(UV, costs_uv);
    Dijkstra(VU, costs_vu);
    
    for(int i = 1; i <= N; i++)
        res = std::max(res, costs_uv[i] + costs_vu[i]);
    std::cout << res;
    return 0;
}
