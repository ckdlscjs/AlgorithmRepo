#include <bits/stdc++.h>
int T, N, M, a, b;
bool DFS(const std::vector<int>* graphs, std::vector<int>& colors, int cur, int color)
{
  colors[cur] = color;
  for(const auto& iter : graphs[cur])
  {
    if(colors[iter] != 0 && colors[iter] != color) continue;
    if(colors[iter] != 0 && colors[iter] == color) return false;
    if(!DFS(graphs, colors, iter, color * -1)) return false;
  }
  return true;
}

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  for(int t = 0; t < T; t++)
  {
    std::cin >> N >> M;
    std::vector<int> colors(N+1, 0);
    std::vector<int> graph[2'005];
    for(int m = 0; m < M; m++)
    {
      std::cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    bool flag = true;
    for(int i = 1; i <= N; i++)
    {
      if(colors[i] != 0) continue;
      if(!DFS(graph, colors, i, 1))
      {
        flag = false;
        break;
      }
    }
    std::cout << "Scenario #" << t+1<<":\n";
    std::cout << (flag ? "No suspicious bugs found!" : "Suspicious bugs found!") << '\n' << '\n';
  }
 
  return 0;
}