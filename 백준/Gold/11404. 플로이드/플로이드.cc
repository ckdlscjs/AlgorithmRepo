#include <bits/stdc++.h>
const int INF = 987654321;
int costs[105][105];
int n, m, a, b, c;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::fill(&costs[0][0], &costs[104][105], INF);
  std::cin >> n >> m;
  for(int i = 1; i <= m; i++)
  {
    std::cin >> a >> b >> c;
    costs[a][b] = std::min(costs[a][b], c);
  }
  for(int i = 1; i <= n; i++)
    costs[i][i] = 0;
  for(int mid = 1; mid <= n; mid++)
    for(int u = 1; u <= n; u++)
      for(int v = 1; v <= n; v++)
        costs[u][v] = std::min(costs[u][v], costs[u][mid] + costs[mid][v]);
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      std::cout << (costs[i][j] == INF ? 0 : costs[i][j]) << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}