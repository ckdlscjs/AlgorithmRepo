#include <bits/stdc++.h>
int N, M, a, b, c, reshi, reslow;
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
  std::cin >> N >> M;
  DisjointSet ds_low(N), ds_hi(N);
  std::cin >> a >> b >> c;
  ds_low.Union(a, b);
  ds_hi.Union(a, b);
  reshi += c ? 0 : 1;
  reslow += c ? 0 : 1;
  for(int m = 0; m < M; m++)
  {
    std::cin >> a >> b >> c;
    edges.push_back({(c ? 0 : 1), {a, b}});
  }
  std::sort(edges.begin(), edges.end(), std::less<>());
  for(int m = 0; m < M; m++)
  {
    int c = edges[m].first;
    int a = edges[m].second.first;
    int b = edges[m].second.second;
    if(ds_low.Find(a) == ds_low.Find(b)) continue;
    ds_low.Union(a, b);
    reslow += c;
  }
  std::sort(edges.begin(), edges.end(), std::greater<>());
  for(int m = 0; m < M; m++)
  {
    int c = edges[m].first;
    int a = edges[m].second.first;
    int b = edges[m].second.second;
    if(ds_hi.Find(a) == ds_hi.Find(b)) continue;
    ds_hi.Union(a, b);
    reshi += c;
  }
  std::cout << reshi*reshi - reslow*reslow;
  return 0;
}