#include <bits/stdc++.h>
int V, u, v, w;
std::vector<std::pair<int, int>> graph[100'005];
std::pair<int, int> BFS(int idx)
{
  std::pair<int, int> ret;
  int dist[100'005];
  std::memset(dist, 0, sizeof(dist));
  std::queue<int> q;
  dist[idx] = 1;
  q.push(idx);
  while(q.size())
  {
    int cur = q.front();
    q.pop();
    if(ret.second < dist[cur])
    {
      ret.second = dist[cur];
      ret.first = cur;
    }
    for(const auto& iter : graph[cur])
    {
      if(dist[iter.first])
        continue;
      dist[iter.first] = dist[cur] + iter.second;
      q.push(iter.first);
    }
  }
  return ret;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> V;
  for(int i = 0; i < V; i++)
  {
    std::cin>>u;
    while(std::cin >> v && v != -1)
    {
      std::cin >> w;
      graph[u].push_back({v, w});
      graph[v].push_back({u, w});
    }
  }
  std::pair<int, int> ret1 = BFS(1);
  std::pair<int, int> ret2 = BFS(ret1.first);
  std::cout <<ret2.second-1;
  return 0;
}