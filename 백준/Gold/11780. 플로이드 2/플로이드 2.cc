#include <bits/stdc++.h>
const int INF = 987654321;
int N, M, costs[105][105], nxt[105][105], A, B, C;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::fill_n(&costs[0][0], 105*105, INF);
  std::fill_n(&nxt[0][0], 105*105, INF);
  std::cin >> N >> M;
  for(int i = 1; i <= N; i++)
  {
    costs[i][i] = 0;
    nxt[i][i] = 0;
  }
  for(int m = 0; m < M; m++)
  {
    std::cin >> A >> B >> C;
    costs[A][B] = std::min(costs[A][B], C);
    nxt[A][B] = B;
  }
  for(int k = 1; k <= N; k++)
  {
    for(int i = 1; i <= N; i++)
    {
      for(int j = 1; j <= N; j++)
      {
        if(costs[i][k] != INF && costs[k][j] != INF && costs[i][k] + costs[k][j] < costs[i][j])
        {
          costs[i][j] = costs[i][k] + costs[k][j];
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }
  
  for(int i = 1; i <= N; i++)
  {
    for(int j = 1; j <= N; j++)
    {
      std::cout << (costs[i][j] == INF ? 0 : costs[i][j]) << ' ';  
    }
    std::cout << '\n';
  }
  
  for(int i = 1; i <= N; i++)
  {
    for(int j = 1; j <= N; j++)
    {
      if(costs[i][j] == INF)
      {
        std::cout << 0 << '\n';
        continue;
      }
      std::vector<int> paths;
      int cur = i;
      while(cur != j)
      {
        paths.push_back(cur);
        cur = nxt[cur][j];
      }
      if(paths.size())
        paths.push_back(j);
      std::cout << paths.size() << ' ';
      for(const auto& iter : paths)
        std::cout << iter << ' ';
      std::cout << '\n';
    }
  }
  
  return 0;
}