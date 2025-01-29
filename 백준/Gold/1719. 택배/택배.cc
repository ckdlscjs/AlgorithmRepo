#include <bits/stdc++.h>
const int INF = 987654321;
int N, M, dists[205][205], nxt[205][205], u, v, w;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  std::fill_n(&dists[0][0], 205*205, INF);
  std::fill_n(&nxt[0][0], 205*205, INF);
  for(int i = 1; i <= N; i++)
  {
    dists[i][i] = 0;
    nxt[i][i] = 0;
  }
  for(int m = 0; m < M; m++)
  {
    std::cin >> u >> v >> w;
    if(w < dists[u][v])
    {
      dists[u][v] = w;
      nxt[u][v] = v;
    }
    if(w < dists[v][u])
    {
      dists[v][u] = w;
      nxt[v][u] = u;
    }
  }
  for(int k = 1; k <= N; k++)
  {
    for(int i = 1; i <= N; i++)
    {
      for(int j = 1; j <= N; j++)
      {
        if(dists[i][k] != INF && dists[k][j] != INF && dists[i][k] + dists[k][j] < dists[i][j])
        {
          dists[i][j] = dists[i][k] + dists[k][j];
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }
  for(int i = 1; i <= N; i++)
  {
    for(int j = 1; j <= N; j++)
    {
      if(nxt[i][j])
        std::cout << nxt[i][j] << ' ';
      else
        std::cout << '-' << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}