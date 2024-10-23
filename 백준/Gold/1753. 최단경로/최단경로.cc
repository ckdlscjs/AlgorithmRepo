#include <bits/stdc++.h>
const int INF = 987654321;
int V, E, K, u, v, w;
int costs[20'005];
std::vector<std::pair<int, int>> graph[20'005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> V >> E >> K;
    for(int i = 0; i < E; i++)
    {
      std::cin >> u >> v >> w;
      graph[u].push_back({v, w});
    }
    std::fill(costs, costs+20'005, INF);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, K});
    costs[K] = 0;
    while(pq.size())
    {
      int w = pq.top().first;
      int u = pq.top().second;
      pq.pop();
      for(const auto& iter : graph[u])
      {
        int v = iter.first;
        int nw = iter.second;
        if(costs[u] + nw < costs[v])
        {
          costs[v] = costs[u] + nw;
          pq.push({costs[v], v});
        }
      }
    }
    for(int i = 1; i <= V; i++)
      if(costs[i] == INF)
        std::cout << "INF" << '\n';
      else
        std::cout << costs[i] << '\n';
    return 0;
}