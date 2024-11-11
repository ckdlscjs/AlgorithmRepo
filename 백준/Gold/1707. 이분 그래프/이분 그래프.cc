#include <bits/stdc++.h>
int K, V, E, u, v;
bool DFS(std::unordered_map<int, std::vector<int>>& graph, int cur, std::vector<int>& colors, int color)
{
  bool ret = true;
  colors[cur] = color;
  for(const auto& iter : graph[cur])
  {
    if(colors[iter] && colors[iter] == color) return false;
    if(colors[iter] == 0)
    {
      ret = DFS(graph, iter, colors, color*-1);
      if(!ret) return ret;
    }
  }
  return ret;
}
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> K;
  for(int k = 0; k < K; k++)
  {
    std::cin >> V >> E;
    std::unordered_map<int, std::vector<int>> graph;
    std::vector<int> colors(V+1, 0);
    for(int i = 0; i < E; i++)
    {
      std::cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    bool chk = true;
    for(int i = 1; i <= V; i++)
    {
      if(colors[i]) continue;
      chk = DFS(graph, i, colors, 1);
      if(!chk)
        break;
    }
    std::cout << (chk ? "YES" : "NO") << '\n';
  }
  return 0;
}