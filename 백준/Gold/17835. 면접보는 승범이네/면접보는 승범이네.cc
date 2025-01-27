#include <bits/stdc++.h>
#define ll long long int
#define plli std::pair<ll, ll>
const ll INF = 10'000'000'005;
ll N, M, K, U, V, C, costs[100'005];
std::vector<plli> graph[100'005];
std::priority_queue<plli, std::vector<plli>, std::greater<plli>> pq;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M >> K;
  for(int m = 0; m < M; m++)
  {
    std::cin >> U >> V >> C;
    graph[V].push_back({U, C});
  }
  std::fill_n(costs, 100'005, INF);
  for(int k = 0; k < K; k++)
  {
    std::cin >> U;
    costs[U] = 0;
    pq.push({0, U});
  }
  while(pq.size())
  {
    ll cost = pq.top().first;
    ll from = pq.top().second;
    pq.pop();
    if(costs[from] < cost) continue;
    for(const auto& iter : graph[from])
    {
      ll to = iter.first;
      ll weight = iter.second;
      if(costs[from] + weight < costs[to])
      {
        costs[to] = costs[from] + weight;
        pq.push({costs[to], to});
      }
    }
  }
  plli result(0, 0);
  for(int i = N; i >= 1; i--)
  {
    if(costs[i] != INF && result.second <= costs[i])
    {
      result.first = i;
      result.second = costs[i];
    }
  }
  std::cout << result.first << '\n' << result.second;
  return 0;
}