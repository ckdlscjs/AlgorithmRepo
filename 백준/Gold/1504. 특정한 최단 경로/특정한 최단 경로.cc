#include <bits/stdc++.h>
#define pii std::pair<int, int>
const int INF = 987654321;
int N, E, a, b, c, u, v, costs[805];
std::vector<pii> graph[805];
void dijkstra(int start)
{
  std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
  std::fill_n(costs, 805, INF);
  costs[start] = 0;
  pq.push({0, start});
  while(pq.size())
  {
    int cost = pq.top().first;
    int from = pq.top().second;
    pq.pop();
    if(costs[from] < cost) continue;
    for(const auto& iter : graph[from])
    {
      int to = iter.first;
      int dist = iter.second;
      if(costs[from] + dist < costs[to])
      {
        costs[to] = costs[from] + dist;
        pq.push({costs[to], to});
      }
    }
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> E;
  for(int e = 0; e < E; e++)
  {
    std::cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
  std::cin >> u >> v;
  dijkstra(u);
  int duv = costs[v];
  if(duv == INF)
  {
    std::cout << -1;
    return 0;
  }
  dijkstra(1);
  int d1u = costs[u];
  int d1v = costs[v];
  dijkstra(N);
  int dnv = costs[v];
  int dnu = costs[u];
  int dmin = std::min(d1u + dnv, d1v + dnu);
  if(dmin >= INF)
  {
    std::cout << -1;
    return 0;
  }
  std::cout << dmin + duv;
  return 0;
}