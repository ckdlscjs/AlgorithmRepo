#include <bits/stdc++.h>
int N, M, a, b, c;
std::vector<std::pair<int, int>> graph[10'005];
bool visited[10'005];
void dfs(int cur, int mid)
{
  visited[cur] = true;
  for(const auto& iter : graph[cur])
  {
    if(visited[iter.first] || mid > iter.second) continue;
    dfs(iter.first, mid);
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int m = 0; m < M; m++)
  {
    std::cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
  std::cin >> a >> b;
  int lo = 0, hi = 1'000'000'005;
  while(lo + 1 < hi)
  {
    int mid = (lo + hi) / 2;
    dfs(a, mid);
    if(visited[b]) lo = mid;
    else hi = mid;
    std::memset(visited, false, sizeof(visited));
  }
  std::cout << lo;
  return 0;
}