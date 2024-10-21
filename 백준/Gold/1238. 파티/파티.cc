#include <bits/stdc++.h>
using namespace std;
int N, M, X, u, v, w;
const int INF = 987654321;
int costs[1'005][1'005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::fill(&costs[0][0], &costs[1'004][1'005], INF);
  std::cin >> N >> M >> X;
  for(int i = 1; i <= N; i++)
    costs[i][i] = 0;
  for(int i = 0; i < M; i++)
  {
    std::cin >> u >> v >> w;
    costs[u][v] = w;
  }
  for(int m = 1; m <= N; m++)
    for(int a = 1; a <= N; a++)
      for(int b = 1; b <= N; b++)
        costs[a][b] = std::min(costs[a][b], costs[a][m] + costs[m][b]);
  int res = 0;
  for(int i = 1; i <= N; i++)
    res = std::max(res, costs[i][X] + costs[X][i]);
  std::cout << res;
  return 0;
}