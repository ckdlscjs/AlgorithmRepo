#include <bits/stdc++.h>
int T, N, K, M, u, v;
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
  std::cin >> T;
  for(int t = 0; t < T; t++)
  {
    std::cin >> N;
    DisjointSet ds(N);
    std::cin >> K;
    for(int k = 0; k < K; k++)
    {
      std::cin >> u >> v;
      ds.Union(u, v);
    }
    std::cin >> M;
    std::cout << "Scenario " << t+1 << ":\n";
    for(int m = 0; m < M; m++)
    {
      std::cin >> u >> v;
      std::cout << (ds.Find(u) == ds.Find(v) ? 1 : 0) << '\n';
    }
    std::cout << '\n';
  }
  return 0;
}