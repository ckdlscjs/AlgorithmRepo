#include <bits/stdc++.h>
using namespace std;
const int LOG = 20;
int N, M, u, v, w, d[100'005], dp[LOG][100'005];
long long int costs[100'005];
std::vector<std::pair<int, int>> trees[100'005];
bool visited[100'005];
void DFS(int cur, int depth, long long int cost)
{
  visited[cur] = true;
  d[cur] = depth;
  costs[cur] = cost;
  for(const auto& iter :  trees[cur])
  {
    if(visited[iter.first]) continue;
    dp[0][iter.first] = cur;
    DFS(iter.first, depth+1, cost + iter.second);
  }
}
int LCA(int a, int b)
{
  if(d[a] > d[b]) std::swap(a, b);
  for(int l = LOG-1; l >= 0; l--)
  {
    if(d[b] - d[a] >= (1<<l))
    {
      b = dp[l][b];
    }
  }
  if(a == b) return a;
  for(int l = LOG-1; l >= 0; l--)
  {
    if(dp[l][b] != dp[l][a])
    {
      a = dp[l][a];
      b = dp[l][b];
    }
  }
  return dp[0][a];
}

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 0; n < N-1; n++)
  {
    std::cin >> u >> v >> w;
    trees[u].push_back({v, w});
    trees[v].push_back({u, w});
  }
  DFS(1, 0, 0);
  for(int p = 1; p < LOG; p++)
    for(int node = 1; node <= N; node++)
      dp[p][node] = dp[p-1][dp[p-1][node]];
  std::cin >> M;
  for(int m = 0; m < M; m++)
  {
    std::cin >> u;
    if(u == 1)
    {
      std::cin >> u >> v;
      std::cout << costs[u] + costs[v] - 2*costs[LCA(u, v)] << '\n';
    }
    else
    {
      std::cin >> u >> v >> w;
      int ancestor = LCA(u, v);
      int cnt_ancestor = d[u] - d[ancestor] + 1;
      if(w == cnt_ancestor)
      {
        std::cout << ancestor << '\n';
      }
      else if(w < cnt_ancestor)
      {
        w--;
        for(int l = LOG-1; l >= 0; l--)
        {
          if(w & (1 << l))
            u = dp[l][u];
        }
        std::cout << u << '\n';
      }
      else
      {
        w = cnt_ancestor + d[v] - d[ancestor] + 1 - w;
        w--;
        for(int l = LOG-1; l >= 0; l--)
        {
          if(w & (1 << l))
            v = dp[l][v];
        }
        std::cout << v << '\n';
      }
    }
  }
  
  return 0;
}
