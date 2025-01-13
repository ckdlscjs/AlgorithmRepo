#include <bits/stdc++.h>
int N, M, a, b, tc = 1;
bool DFS(std::vector<bool>& visited, std::vector<int>* graph, int cur, int prev)
{
  visited[cur] = true;
  for(const auto& iter : graph[cur])
  {
    if(iter == prev) continue;
    if(visited[iter]) return false;
    if(!DFS(visited, graph, iter, cur))
      return false;
  }
  return true;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  while(1)
  {
    std::cin >> N >> M;
    if(N == 0 && M == 0)
      return 0;
    std::vector<int> graph[505];
    std::vector<bool> visited(N+1, false);
    int cnt = 0;
    for(int m = 0; m < M; m++)
    {
      std::cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    for(int i = 1; i <= N; i++)
    {
      if(visited[i]) continue;
      if(!DFS(visited, graph, i, -1))
        continue;
      cnt++;
    }
    std::cout << "Case " <<tc++<<": ";
    if(cnt > 1)
      std::cout << "A forest of " << cnt << " trees.\n";
    else if(cnt == 1)
      std::cout << "There is one tree.\n";
    else
      std::cout << "No trees.\n";
  }
  return 0;
}