#include <bits/stdc++.h>
int n, m, u, v, w, weights, cnt;
std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<std::pair<int, std::pair<int, int>>>> pq;
struct DisjointSet
{
  std::vector<int> parents;
  std::vector<int> ranks;
  DisjointSet(int _s) : parents(_s+1, -1), ranks(_s+1, 0) {}
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
    if(ranks[root1] = ranks[root2])
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
  std::cin >> n >> m;
  DisjointSet ds(n);
  for(int i = 0; i < m; i++)
  {
    std::cin >> u >> v >> w;
    pq.push({w, {u, v}});
  }
  while(pq.size() && cnt < n)
  {
    w = pq.top().first;
    u = pq.top().second.first;
    v = pq.top().second.second;
    pq.pop();
    if(ds.IsCycle(u, v))
      continue;
    ds.Union(u, v);
    weights += w;
    cnt++;
  }
  
  std::cout << weights;
  return 0;
}