#include <bits/stdc++.h>
int N, M, u, v, w;
std::vector<std::pair<int, int>> graph[1005];
int DFS(std::vector<bool>& visited, const int& target, int cur, int dist)
{
  if(cur == target)
    return dist;
  visited[cur] = true;
  for(const auto& iter : graph[cur])
  {
    if(visited[iter.first]) continue;
    int temp = DFS(visited, target, iter.first, dist + iter.second);
    if(temp) return temp;
  }
  return 0;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int n = 0; n < N-1; n++)
  {
    std::cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }
  for(int m = 0; m < M; m++)
  {
    std::cin >> u >> v;
    std::vector<bool> visited(N+1, false);
    std::cout << DFS(visited, v, u, 0) << '\n';
  }
  return 0;
}