#include <bits/stdc++.h>
#define ll long long int
const ll INF = 1e14+5;
ll N, M, A, B, C, u, v, w, maxW, costs[100'005], minCost = INF;
std::vector<std::pair<ll, ll>> graph[100'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M >> A >> B >> C;
  for(int i = 0; i < M; i++)
  {
    std::cin >> u >> v >> w;
    graph[u].push_back({w, v});
    graph[v].push_back({w, u});
    maxW = std::max(maxW, w);
  }
  ll lo = -1, hi = maxW+1;
  while(lo + 1 < hi)
  {
    ll mid = (lo + hi) / 2;
    std::fill_n(costs, 100'005, INF);
    costs[A] = 0;
    std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll>>, std::greater<std::pair<ll, ll>>> pq;
    pq.push({0, A});
    while(pq.size())
    {
      ll u = pq.top().second;
      ll c = pq.top().first;
      pq.pop();
      if(costs[u] < c) continue;
      for(const auto& iter : graph[u])
      {
        if(iter.first <= mid && costs[u] + iter.first < costs[iter.second] && c + iter.first <= C)
        {
          costs[iter.second] = costs[u] + iter.first;
          pq.push({costs[iter.second], iter.second});
        }
      }
    }
    if(costs[B] <= C) hi = mid;
    else lo = mid;
  }
  std::cout << (hi > maxW ? -1 : hi);
  return 0;
}