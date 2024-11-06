#include <bits/stdc++.h>
const int INF = 98765421;
int N, M, u, v, w;
std::vector<std::pair<std::pair<int, int>, int>> edges;
long long int costs[505];
bool Bellmanford(int s)
{
  costs[s] = 0;
  for(int i = 0; i < N; i++)
  {
    for(const auto& iter : edges)
    {
      int u = iter.first.first;
      int v = iter.first.second;
      int w = iter.second;
      if(costs[u] != INF && costs[u] + w < costs[v])
      {
        costs[v] = costs[u] + w;
        if(i == N-1)
          return false;
      }
    }
  }
  return true;
}
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::fill_n(costs, 505, INF);
  std::cin >> N >> M;
  for(int i = 0; i < M; i++)
  {
    std::cin >> u >> v >> w;
    edges.push_back({{u, v}, w});
  }
  if(Bellmanford(1))
  {
    for(int i = 2; i <= N; i++)
      std::cout << (costs[i] == INF ? -1 : costs[i]) << '\n';
  }
  else
    std::cout << -1;
  return 0;
}