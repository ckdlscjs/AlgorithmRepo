#include <bits/stdc++.h>
const long long int INF = 30'000'000'005;
int N, M, a, b, c;
long long int costs[505];
std::vector<std::tuple<int, int, int>> edges;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  std::fill_n(costs, 505, INF);
  for(int m = 0; m < M; m++)
  {
    std::cin >> a >> b >> c;
    edges.push_back(std::make_tuple(a, b, c));
  }
  costs[1] = 0;
  for(int i = 0; i < N; i++)
  {
    for(const auto& iter : edges)
    {
      a = std::get<0>(iter);
      b = std::get<1>(iter);
      c = std::get<2>(iter);
      if(costs[a] != INF && costs[a] + c < costs[b])
      {
        costs[b] = costs[a] + c;
        if(i == N-1)
        {
          std::cout << -1;
          return 0;
        }
      }
    }
  }
  for(int i = 2; i <= N; i++)
    std::cout << (costs[i] == INF ? -1 : costs[i]) << '\n';
  return 0;
}