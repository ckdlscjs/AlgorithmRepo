#include <bits/stdc++.h>
int N, M, K, u, v, w, sum;
std::vector<std::pair<int, std::pair<int, int>>> edges;
struct DisjointSet
{
  std::vector<int> parents;
  std::vector<int> ranks;
  DisjointSet(int _size) : parents(_size+1, -1), ranks(_size+1, 0) {}
  int Find(int node)
  {
    if(parents[node] == -1) return node;
    return parents[node] = Find(parents[node]);
  }
  void Union(int node1, int node2)
  {
    int root1 = Find(node1);
    int root2 = Find(node2);
    if(root1 == root2) return;
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
  std::cin >> N >> M >> K;
  DisjointSet ds(N);
  for(int k = 0; k < K; k++)
  {
    std::cin >> u;
    ds.ranks[u] = 1005;
  }
  for(int m = 0; m < M; m++)
  {
    std::cin >> u >> v >> w;
    edges.push_back({w, {u, v}});
  }
  std::sort(edges.begin(), edges.end(), std::less<>());
  for(int i = 0; i < edges.size(); i++)
  {
    w = edges[i].first;
    u = edges[i].second.first;
    v = edges[i].second.second;
    if(ds.ranks[ds.Find(u)] >= 1005 && ds.ranks[ds.Find(v)] >= 1005) continue;
    if(ds.Find(u) != ds.Find(v))
    {
      ds.Union(u, v);
      sum += w;
    }
  }
  /*
  for(int i = 1; i <= N; i++)
    std::cout << ds.Find(i) << ' ';
  */
  std::cout << sum;
  return 0;
}