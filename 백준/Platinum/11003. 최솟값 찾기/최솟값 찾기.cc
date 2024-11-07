#include <bits/stdc++.h>
int N, L, val;
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> L;
  for(int i = 0; i < N; i++)
  {
    std::cin >> val;
    pq.push({val, i});
    while(pq.top().second < i - L + 1)
      pq.pop();
    std::cout << pq.top().first << ' ';
  }
  return 0;
}