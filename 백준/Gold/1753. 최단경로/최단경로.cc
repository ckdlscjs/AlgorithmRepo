#include <bits/stdc++.h>
const int INF = 98765421;
int V, E, K, u, v, w;
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
std::vector<std::pair<int, int>> graph[20'005];
int costs[20'005];
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::fill_n(costs, 20'005, INF);
  std::cin >> V >> E >> K;
  for(int i = 0; i < E; i++)
  {
    std::cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }
  pq.push({0, K});
  costs[K] = 0;
  while(pq.size())
  {
    int u = pq.top().second;
    int w = pq.top().first;
    pq.pop();
    if(costs[u] < w)
      continue;
    for(const auto& iter : graph[u])
    {
      if(costs[u] + iter.second >= costs[iter.first]) continue;
      costs[iter.first] = costs[u] + iter.second;
      pq.push({costs[iter.first], iter.first});
    }
  }
  for(int i = 1; i <= V; i++)
  {
    if(costs[i] == INF)
      std::cout << "INF" << '\n';
    else
      std::cout << costs[i] << '\n';
  }
  return 0;
}