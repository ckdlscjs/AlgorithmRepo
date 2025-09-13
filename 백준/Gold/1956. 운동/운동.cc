#include <bits/stdc++.h>
const int INF = 987654321;
int dist[405][405];
int V, E, a, b, c, res = INF;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::fill_n(&dist[0][0], 405*405, INF);
  std::cin >> V >> E;
  for(int e = 0; e < E; e++)
  {
    std::cin >> a >> b >> c;
    dist[a][b] = c;
  }
  for(int i = 1; i <= V; i++) dist[i][i] = 0;
  for(int i = 1; i <= V; i++)
  {
    for(int j = 1; j <= V; j++)
    {
      for(int k = 1; k <= V; k++)
      {
        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  for(int i = 1; i <= V; i++)
  {
    for(int j = i+1; j <= V; j++)
    {
      if(dist[i][j] != INF && dist[j][i] != INF)
        res = std::min(res, dist[i][j] + dist[j][i]);
    }
  }
  std::cout << (res == INF ? -1 : res);
  return 0;
}