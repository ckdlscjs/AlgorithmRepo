#include <bits/stdc++.h>
int N, M, q, a, b;
struct DisjointSet
{
  std::vector<int> parents;
  DisjointSet(int _size) : parents(_size+1, -1) {}
  int Find(int node)
  {
    if(parents[node] == -1)
      return node;
    return parents[node] = Find(parents[node]);
  }
  void Union(int node1, int node2)
  {
    int root1 = Find(node1);
    int root2 = Find(node2);
    if(root1 == root2) return;
    parents[root2] = root1;
  }
};
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  DisjointSet ds(N);
  for(int m = 0; m < M; m++)
  {
    std::cin >> q >> a >> b;
    if(!q)
    {
      ds.Union(a, b);
      continue;
    }
    std::cout << (ds.Find(a) == ds.Find(b) ? "YES" : "NO") << '\n';
  }
  return 0;
}