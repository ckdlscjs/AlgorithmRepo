#include <bits/stdc++.h>
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
long long int res;
int N;
std::pair<int, int> arrX[100'005];
std::pair<int, int> arrY[100'005];
std::pair<int, int> arrZ[100'005];
std::vector<std::pair<int, std::pair<int, int>>> inputs;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  DisjointSet ds(N);
  for(int n = 0; n < N; n++)
  {
    std::cin >> arrX[n].first >> arrY[n].first >> arrZ[n].first;
    arrX[n].second = arrY[n].second = arrZ[n].second = n;
  }
  std::sort(arrX, arrX+N, std::less<>());
  std::sort(arrY, arrY+N, std::less<>());
  std::sort(arrZ, arrZ+N, std::less<>());
  for(int n = 1; n < N; n++)
  {
    inputs.push_back({std::abs(arrX[n].first - arrX[n-1].first), {arrX[n-1].second, arrX[n].second}});
    inputs.push_back({std::abs(arrY[n].first - arrY[n-1].first), {arrY[n-1].second, arrY[n].second}});
    inputs.push_back({std::abs(arrZ[n].first - arrZ[n-1].first), {arrZ[n-1].second, arrZ[n].second}});
  }
  std::sort(inputs.begin(), inputs.end(), std::less<>());
  for(const auto& iter : inputs)
  {
    int dist = iter.first;
    int u = iter.second.first;
    int v = iter.second.second;
    if(ds.Find(u) != ds.Find(v))
    {
      ds.Union(u, v);
      res += dist;
    }
  }
  std::cout << res;
  return 0;
}