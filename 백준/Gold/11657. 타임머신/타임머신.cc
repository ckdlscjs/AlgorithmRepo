#include <bits/stdc++.h>
const int INF = 987654321;
int N, M, a, b, c;
std::vector<std::pair<std::pair<int, int>, int>> edges;
long long int costs[505];
bool Bellmanford(int s)
{
  costs[s] = 0;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < edges.size(); j++)
    {
      int u = edges[j].first.first;
      int v = edges[j].first.second;
      int w = edges[j].second;
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
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  std::fill(costs, costs+505, INF);
  for(int i = 0; i < M; i++)
  {
    std::cin >> a >> b >> c;
    edges.push_back({{a, b}, c});
  }
  if(Bellmanford(1))
  {
    for(int i = 2; i <= N; i++)
      std::cout << (costs[i] == INF ? -1 : costs[i]) << '\n';
    return 0;
  }
  std::cout << -1;
  return 0;
}