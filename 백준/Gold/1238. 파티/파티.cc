#include <bits/stdc++.h>
using namespace std;
int N, M, X, u, v, w;
const int INF = 987654321;
int costs_xu[1'005];
std::vector<std::pair<int, int>> graph_uv[1'005];
int costs_xv[1'005];
std::vector<std::pair<int, int>> graph_vu[1'005];
void Dijkstra(const std::vector<std::pair<int, int>>* graph, int* costs)
{
  std::fill(costs, costs+1'005, INF);
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> pq;
  pq.push({0, X});
  costs[X] = 0;
  while(pq.size())
  {
    std::pair<int, int> cur = pq.top();
    pq.pop();
    if(cur.first > costs[cur.second]) continue;
    for(int i = 0; i < graph[cur.second].size(); i++)
    {
      int v = graph[cur.second][i].first;
      int w = graph[cur.second][i].second;
      if(costs[v] > cur.first + w)
      {
        costs[v] = cur.first + w;
        pq.push({costs[v], v});
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
  for(int i = 0; i < M; i++)
  {
    std::cin >> u >> v >> w;
    graph_uv[u].push_back({v, w});
    graph_vu[v].push_back({u, w});
  }
  Dijkstra(graph_vu, costs_xu);
  Dijkstra(graph_uv, costs_xv);
  int res = 0;
  for(int i = 1; i <= N; i++)
    res = std::max(res, costs_xv[i] + costs_xu[i]);
  std::cout << res;
  return 0;
}