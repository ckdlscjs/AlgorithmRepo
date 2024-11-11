#include <bits/stdc++.h>
long long int A, B;
std::unordered_map<long long int, int> dist;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> A >> B;
  std::queue<int> q;
  dist[A] = 1;
  q.push(A);
  while(q.size())
  {
    long long int cur = q.front();
    q.pop();
    if(cur * 2 <= 1e9 && dist.find(cur*2) == dist.end())
      dist[cur*2] = dist[cur]+1, q.push(cur*2);
    if(cur *10 + 1 <= 1e9 && dist.find(cur *10 + 1) == dist.end())
      dist[cur *10 + 1] = dist[cur]+1, q.push(cur *10 + 1);
  }
  if(dist.find(B) == dist.end())
    std::cout << -1;
  else
    std::cout << dist[B];
  return 0;
}