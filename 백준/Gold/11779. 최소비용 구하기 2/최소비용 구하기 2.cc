#include <bits/stdc++.h>
const int INF = 987654321;
int N, M, u, v, w, costs[2005], parents[2005];
std::vector<std::pair<int, int>> graph[1'005];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  
  std::cin >> N >> M;
  for(int m = 0; m < M; m++)
  {
    std::cin >> u >> v >> w;
    graph[u].push_back({v, w});
    //graph[v].push_back({u, w});
  }
  std::fill_n(costs, 2005, INF);
  std::cin >> u >> v;
  costs[u] = 0;
  pq.push({0, u});
  while(pq.size())
  {
    int cost = pq.top().first;
    int from = pq.top().second;
    pq.pop();
    if(costs[from] < cost) continue;
    for(const auto& iter : graph[from])
    {
      int to = iter.first;
      int weight = iter.second;
      if(costs[from] + weight >= costs[to]) continue;
      costs[to] = costs[from] + weight;
      parents[to] = from;
      pq.push({costs[to], to});
    }
  }
  std::cout << costs[v] << '\n';
  std::stack<int> routes;
  int cur = v;
  routes.push(cur);
  while(cur != 0)
  {
    cur = parents[routes.top()];
    if(cur == 0) break;
    routes.push(cur);
  }
  std::cout << routes.size() << '\n';
  while(routes.size())
  {
    std::cout << routes.top() << ' ';
    routes.pop();
  }
  return 0;
}