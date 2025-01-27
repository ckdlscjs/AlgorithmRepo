#include <bits/stdc++.h>
#define pii std::pair<int, int>
const int INF = 987654321;
int N, M, X, U, V, T, costs_xv[1005], costs_xu[1005];
std::vector<pii> graph_uv[1005], graph_vu[1005];
void Dijkstra(const std::vector<pii>* graph, int* costs)
{
  std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
  std::fill_n(costs, 1005, INF);
  costs[X] = 0;
  pq.push({0, X});
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
      if(costs[from] + weight < costs[to])
      {
        costs[to] = costs[from] + weight;
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
  std::cin >> N >> M >> X;
  for(int m = 0; m < M; m++)
  {
    std::cin >> U >> V >> T;
    graph_uv[U].push_back({V, T});
    graph_vu[V].push_back({U, T});
  }
  Dijkstra(graph_uv, costs_xv);
  Dijkstra(graph_vu, costs_xu);
  int res = 0;
  for(int i = 1; i <= N; i++)
  {
    if(costs_xv[i] != INF && costs_xu[i] != INF)
      res = std::max(res, costs_xv[i] + costs_xu[i]);
  }
  std::cout << res;
  return 0;
}