#include <bits/stdc++.h>
int v, e;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); 
  std::cout.tie(0);
  std::cin >> v >> e;
  std::vector<std::pair<int, long long int>> graph[10005];
  for(int i = 0; i < e; i++)
  {
    int a, b, w;
    std::cin >> a >> b >> w;
    graph[a].push_back({b, w});
    graph[b].push_back({a, w});
  }
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
  bool visited[10005];
  std::memset(visited, false, sizeof(visited));
  pq.push({0, 1});
  int weights = 0;
  while(pq.size())
  {
    int w = pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    if(visited[cur])
      continue;
    visited[cur] = true;
    weights += w;
    for(const auto& iter : graph[cur])
    {
      if(visited[iter.first])
        continue;
      pq.push({iter.second, iter.first});
    }
  }
  std::cout << weights;
  return 0;
}