#include <bits/stdc++.h>
using namespace std;
int N, M, u, v;
bool visited[105];
std::vector<int> graph[105];
int DFS(int cur)
{
  int ret = 1;
  visited[cur] = true;
  for(const auto& iter : graph[cur])
  {
    if(visited[iter]) continue;
    ret += DFS(iter);
  }
  return ret;
}
int main() 
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
  std::cout << DFS(1) - 1;
  return 0;
}