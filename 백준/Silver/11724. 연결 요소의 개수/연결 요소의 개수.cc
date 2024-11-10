#include <bits/stdc++.h>
int N, M, u, v, cnt;
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
      ranks[root1]++, parents[root2] = root1;
    else if(ranks[root1] < ranks[root2])
      parents[root1] = root2;
    else
      parents[root2] = root1;
  }
};
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  DisjointSet ds(N);
  for(int i = 0; i < M; i++)
  {
    std::cin >> u >> v;
    if(ds.Find(u) == ds.Find(v)) continue;
    ds.Union(u, v);
  }
  std::unordered_set<int> group;
  for(int i = 1; i <= N; i++)
  {
    group.insert(ds.Find(i));
  }
  std::cout << group.size();
  return 0;
}