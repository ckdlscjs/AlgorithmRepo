#include <bits/stdc++.h>
int N, M, cnt;
std::vector<std::pair<int, std::pair<int, int>>> inputs;
long long int u, v, c, res;
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
  for(int i = 0; i < M; i++)
  {
    std::cin >> u >> v >> c;
    inputs.push_back({c, {u, v}});
  }
  std::sort(inputs.begin(), inputs.end());
  DisjointSet ds(N);
  for(int i = 0; i < inputs.size() && cnt < N-1; i++)
  {
    c = inputs[i].first;
    u = inputs[i].second.first;
    v = inputs[i].second.second;
    if(ds.Find(u) == ds.Find(v)) continue;
    //std::cout << u << ' ' << v << ' ' << c << '\n';
    ds.Union(u, v);
    res += c;
    cnt++;
  }
  std::cout << res - c;
  return 0;
}