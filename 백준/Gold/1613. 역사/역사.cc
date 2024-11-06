#include <bits/stdc++.h>
int n, k, u, v, s;
const int INF = 987654321;
int costs[405][405];
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::fill_n(&costs[0][0], 405*405, INF);
  std::cin >> n >> k;
  for(int i = 0; i < k; i++)
  {
    std::cin >> u >> v;
    costs[u][v] = 1;
  }
  std::cin >> s;
  for(int m = 1; m <= n; m++)
  {
    for(int i = 1; i <= n; i++)
    {
      for(int j = 1; j <= n; j++)
      {
        if(costs[i][m] + costs[m][j] < costs[i][j])
        {
          costs[i][j] = costs[i][m] + costs[m][j];
        }
      }
    }
  }
  for(int i = 0; i < s; i++)
  {
    std::cin >> u >> v;
    if(costs[u][v] == INF && costs[v][u] == INF)
      std::cout << 0 <<'\n';
    else if(costs[u][v] < costs[v][u])
      std::cout << -1 << '\n';
    else
      std::cout << 1 << '\n';
  }
  return 0;
}