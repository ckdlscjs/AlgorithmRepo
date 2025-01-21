#include <bits/stdc++.h>
using namespace std;
int N, M, u, v;
int degree[32'005];
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
std::vector<int> graph[32'005];
void TopologySort()
{
  for(int i = 1; i <= N; i++)
    if(degree[i] == 0)
      pq.push(i);
  for(int i = 1; i <= N; i++)
  {
    if(pq.empty()) return;
    int cur = pq.top();
    pq.pop();
    std::cout << cur << ' ';
    for(const auto& iter : graph[cur])
    {
      degree[iter]--;
      if(degree[iter] <= 0)
      pq.push(iter);
    }
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < M; i++)
  {
    std::cin >> u >> v;
    graph[u].push_back(v);
    degree[v]++;
  }
  TopologySort();
  return 0;
}