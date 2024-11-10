#include <bits/stdc++.h>
int N, M, u, v, cnt;
std::vector<int> graph[1005];
bool visited[1005];
void DFS(int cur)
{
  visited[cur] = true;
  for(const auto& iter : graph[cur])
  {
    if(visited[iter]) continue;
    DFS(iter);
  }
}
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < M; i++)
  {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for(int i = 1; i <= N; i++)
  {
    if(visited[i]) continue;
    DFS(i);
    cnt++;
  }
  std::cout << cnt;
  return 0;
}