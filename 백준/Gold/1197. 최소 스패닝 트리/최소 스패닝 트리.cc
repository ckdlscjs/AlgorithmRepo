#include <bits/stdc++.h>
int v, e;
struct DisjointSet
{
  std::vector<int> parents;
  std::vector<int> ranks;
  DisjointSet(int _size) : parents(_size+1, -1), ranks(_size+1, 0) {}
  int Find(int node)
  {
    if(parents[node] == -1)
      return node;
    return parents[node] = Find(parents[node]);
  }
  bool IsCycle(int node1, int node2)
  {
    return Find(node1) == Find(node2);
  }
  void Union(int node1, int node2)
  {
    int root1 = Find(node1);
    int root2 = Find(node2);
    if(root1 == root2)
      return;
    if(ranks[root1] == ranks[root2])
    {
      ranks[root1]++;
      parents[root2] = root1;
    }
    else if(ranks[root1] > ranks[root2])
    {
      parents[root2] = root1;
    }
    else
    {
      parents[root1] = root2;
    }
  }
};
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); 
  std::cout.tie(0);
  std::cin >> v >> e;
  DisjointSet ds(v);
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
    ds.Union(1, cur);
    weights += w;
    for(const auto& iter : graph[cur])
    {
      if(visited[iter.first])
        continue;
      if(ds.IsCycle(1, iter.first))
        continue;
      pq.push({iter.second, iter.first});
    }
  }
  std::cout << weights;
  return 0;
}