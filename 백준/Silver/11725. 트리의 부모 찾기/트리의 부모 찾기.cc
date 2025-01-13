#include <bits/stdc++.h>
using namespace std;
int N, u, v, parents[100'005];
bool visited[100'005];
std::vector<int> graph[100'005];
void dfs(int cur)
{
  for(const auto& iter : graph[cur])
  {
    if(visited[iter]) continue;
    parents[iter] = cur;
    visited[iter] = true;
    dfs(iter);
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  visited[1] = true;
  dfs(1);
  for(int i = 2; i <= N; i++)
    std::cout << parents[i] << '\n';
  return 0;
}