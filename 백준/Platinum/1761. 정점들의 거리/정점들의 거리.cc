#include <bits/stdc++.h>
using namespace std;
int N, M, u, v, w, d[40'005], dp[20][40'005], costs[20][40'005];
std::vector<std::pair<int, int>> trees[40'005];
bool visited[40'005];
void DFS(int cur, int depth)
{
  visited[cur] = true;
  d[cur] = depth;
  for(const auto& iter : trees[cur])
  {
    if(visited[iter.first]) continue;
    dp[0][iter.first] = cur;
    costs[0][iter.first] = iter.second;
    DFS(iter.first, depth+1);
  }
}
int LCA(int a, int b)
{
  int ret = 0;
  if(a == b) return ret;
  if(d[a] > d[b])
  {
    int temp = a;
    a = b;
    b = temp;
  }
  for(int p = 19; p >= 0; p--)
  {
    if(d[b] - d[a] >= (1 << p))
    {
      ret += costs[p][b];
      b = dp[p][b];
    }
  }
  if(a == b) return ret;
  for(int p = 19; p >= 0; p--)
  {
    if(dp[p][a] != dp[p][b])
    {
      ret += costs[p][a];
      a = dp[p][a];
      ret += costs[p][b];
      b = dp[p][b];
    }
  }
  return ret + costs[0][a] + costs[0][b];
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
  DFS(1, 0);
  for(int p = 1; p < 20; p++)
  {
    for(int node = 1; node <= N; node++)
    {
      dp[p][node] = dp[p-1][dp[p-1][node]];
      costs[p][node] = costs[p-1][node] + costs[p-1][dp[p-1][node]];
    }
  }
  std::cin >> M;
  for(int m = 0; m < M; m++)
  {
    std::cin >> u >> v;
    std::cout << LCA(u, v) << '\n';
  }
  return 0;
}
