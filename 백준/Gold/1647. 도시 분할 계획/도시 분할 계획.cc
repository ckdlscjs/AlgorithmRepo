#include <bits/stdc++.h>
int N, M, cnt;
long long int u, v, c, res;
struct DisjointSet
{
  std::vector<int> parents;
  DisjointSet(int _size) : parents(_size+1, -1)
  {
    
  }
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
std::priority_queue<std::pair<int ,std::pair<int, int>>, std::vector<std::pair<int ,std::pair<int, int>>>, std::greater<std::pair<int ,std::pair<int, int>>>> pq;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < M; i++)
  {
    std::cin >> u >> v >> c;
    pq.push({c, {std::min(u, v), std::max(u, v)}});
  }
  DisjointSet ds(N);
  while(pq.size() && cnt < N-1)
  {
    u = pq.top().second.first;
    v = pq.top().second.second;
    c = pq.top().first;
    pq.pop();
    if(ds.Find(u) == ds.Find(v)) continue;
    //std::cout << u << ' ' << v << ' ' << c << '\n';
    ds.Union(u, v);
    res += c;
    cnt++;
  }
  std::cout << res - c;
  return 0;
}