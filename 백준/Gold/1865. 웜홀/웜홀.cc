#include <bits/stdc++.h>
using namespace std;
int T, N, M, W, u, v, w, costs[505];
const int INF = 987654321;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  for(int t = 0; t < T; t++)
  {
    std::fill_n(costs, 505, INF);
    std::cin >> N >> M >> W;
    std::vector<std::pair<std::pair<int, int>, int>> edges;
    for(int i = 0; i < M; i++)
    {
      std::cin >> u >> v >> w;
      edges.push_back({{u, v}, w});
      edges.push_back({{v, u}, w});
    }
    for(int i = 0; i < W; i++)
    {
      std::cin >> u >> v >> w;
      edges.push_back({{u, v}, -w});
    }
    bool negative = false;
    for(int i = 0; i < N; i++)
    {
      for(const auto& iter : edges)
      {
        int u = iter.first.first;
        int v = iter.first.second;
        int w = iter.second;
        if(costs[u] + w < costs[v])
        {
          if(i == N-1)
            negative = true;
          costs[v] = costs[u] + w;
        }
      }
    }
    std::cout << (negative ? "YES" : "NO") << '\n';
  }
  return 0;
}