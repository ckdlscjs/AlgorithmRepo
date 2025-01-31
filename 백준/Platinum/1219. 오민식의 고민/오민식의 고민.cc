#include <bits/stdc++.h>
long long int N, S, E, M, u, v, w, earns[55], costs[55];
std::vector<std::tuple<long long int, long long int, long long int>> edges;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> S >> E >> M;
  for(int m = 0; m < M; m++)
  {
    std::cin >> u >> v >> w;
    edges.push_back(std::make_tuple(u, v, w));
  }
  for(int n = 0; n < N; n++)
  {
    std::cin >> earns[n];
  }
  std::fill_n(costs, 55, LONG_MIN);
  costs[S] = earns[S];
  
  for(int i = 0; i < N+100; i++)
  {
    for(const auto& iter : edges)
    {
      u = std::get<0>(iter);
      v = std::get<1>(iter);
      w = earns[v] - std::get<2>(iter);
      if(costs[u] == LONG_MAX)
      {
        costs[v] = LONG_MAX;
        continue;
      }
      if(costs[u] != LONG_MIN && costs[u] + w > costs[v])
      {
        costs[v] = costs[u] + w;
        if(i >= N-1)
        {
          costs[v] = LONG_MAX;
        }
      }
    }
  }
  if(costs[E] == LONG_MIN)
    std::cout << "gg";
  else if(costs[E] == LONG_MAX)
    std::cout << "Gee";
  else
    std::cout << costs[E];
  return 0;
}