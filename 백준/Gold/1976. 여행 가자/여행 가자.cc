#include <bits/stdc++.h>
const int MaxN = 205;
int n, m;
int adj[MaxN][MaxN];
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
    if(ranks[root1] > ranks[root2])
      parents[root2] = root1;
    else
      parents[root1] = root2;
  }
};
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m;
  DisjointSet ds(n);
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      std::cin >> adj[i][j];
      
      if(adj[i][j] && ds.Find(i) != ds.Find(j))
        ds.Union(i, j);
    }
  }
  int travel[1005];
  for(int i = 0; i < m; i++)
    std::cin >> travel[i];
  int n1 = travel[0];
  
  for(int i = 1; i < m; i++)
  {
    if(ds.Find(n1) != ds.Find(travel[i]))
    {
      std::cout << "NO";
      return 0;
    }
  }
  std::cout << "YES";
  return 0;
}