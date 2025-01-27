#include <bits/stdc++.h>
int N, M, A, B;
double res;
std::pair<double, double> inputs[1005];
std::vector<std::pair<double, std::pair<int, int>>> edges;
struct DisjointSet
{
  std::vector<int> cnts;
  std::vector<int> parents;
  std::vector<int> ranks;
  DisjointSet(int _size) : parents(_size+1, -1), ranks(_size+1, 0), cnts(_size+1, 1) {}
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
      cnts[root1] += cnts[root2];
      cnts[root2] = 0;
    }
    else if(ranks[root1] > ranks[root2])
    {
      parents[root2] = root1;
      cnts[root1] += cnts[root2];
      cnts[root2] = 0;
    }
    else
    {
      parents[root1] = root2;
      cnts[root2] += cnts[root1];
      cnts[root1] = 0;
    }
  }
};
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  DisjointSet ds(N);
  for(int n = 1; n <= N; n++)
    std::cin >> inputs[n].first >> inputs[n].second;
  for(int i = 1; i <= N; i++)
  {
    for(int j = i + 1; j <= N; j++)
    {
      double dist = std::sqrt(std::pow(inputs[i].first - inputs[j].first, 2) + std::pow(inputs[i].second - inputs[j].second, 2));
      edges.push_back({dist, {i, j}});
    }
  }
  for(int m = 0; m < M; m++)
  {
    std::cin >> A >> B;
    if(ds.Find(A) != ds.Find(B))
      ds.Union(A, B);
  }
  std::sort(edges.begin(), edges.end(), std::less<>());
  for(int i = 0; i < edges.size(); i++)
  {
    double dist = edges[i].first;
    int A = edges[i].second.first;
    int B = edges[i].second.second;
    if(ds.cnts[ds.Find(A)] >= N || ds.cnts[ds.Find(B)] >= N) break;
    if(ds.Find(A) == ds.Find(B)) continue;
    ds.Union(A, B);
    res += dist;
  }
  std::cout << std::fixed;
  std::cout.precision(2);
  std::cout << res;
  return 0;
}