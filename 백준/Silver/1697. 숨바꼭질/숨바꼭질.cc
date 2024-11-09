#include <bits/stdc++.h>
int dist[100'005];
int N, K;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> K;
  std::queue<int> q;
  q.push(N);
  dist[N] = 1;
  while(q.size())
  {
    int cur = q.front();
    q.pop();
    if(cur-1 >= 0 && !dist[cur-1])
    {
      dist[cur-1] = dist[cur]+1;
      q.push(cur-1);
    }
    if(cur + 1 <= 100'000 && !dist[cur+1])
    {
      dist[cur+1] = dist[cur] + 1;
      q.push(cur+1);
    }
    if(cur*2 <= 100'000 && !dist[cur*2])
    {
      dist[cur*2] = dist[cur]+1;
      q.push(cur*2);
    }
  }
  std::cout << dist[K] - 1;
  return 0;
}