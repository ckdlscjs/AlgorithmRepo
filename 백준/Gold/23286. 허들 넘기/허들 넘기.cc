#include <bits/stdc++.h>
const int INF = 987654321;
int N, M, T, u, v, h, heights[305][305];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M >> T;
  std::fill_n(&heights[0][0], 305*305, INF);
  for(int m = 0; m < M; m++)
  {
    std::cin >> u >> v >> h;
    heights[u][v] = std::min(heights[u][v], h);
  }
  for(int i = 1; i <= N; i++) heights[i][i] = 0;
  for(int k = 1; k <= N; k++)
  {
    for(int i = 1; i <= N; i++)
    {
      for(int j = 1; j <= N; j++)
      {
        heights[i][j] = std::min(heights[i][j], std::max(heights[i][k], heights[k][j]));
      }
    }
  }
  for(int t = 0; t < T; t++)
  {
    std::cin >> u >> v;
    std::cout << (heights[u][v] == INF ? -1 : heights[u][v]) << '\n';
  }
  return 0;
}