#include <bits/stdc++.h>
int N, M, dist[1'000'005], res;
std::queue<int> q;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < M; i++)
  {
    int val;
    std::cin >> val;
    dist[val] = 1;
    q.push(val);
  }
  while(q.size())
  {
    int cur = q.front();
    q.pop();
    res = std::max(res, dist[cur]);
    for(int i = 0; i <= 20; i++)
    {
      int nxt = cur ^ (1 << i);
      if(nxt > N) continue;
      if(dist[nxt]) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }
  std::cout << res-1;
  return 0;
}