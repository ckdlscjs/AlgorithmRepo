#include <bits/stdc++.h>
#define pii std::pair<int, int>
const int INF = 987654321;
int N, E, a, b, c, u, v, costs[1005];
std::vector<pii> graph[1005];
void dijkstra(int start)
{
  std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
  std::fill_n(costs, 1005, INF);
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
  }
  std::cin >> u >> v;
  dijkstra(u);
  std::cout << costs[v];
  return 0;
}