#include <bits/stdc++.h>
int N, L, val;
std::deque<std::pair<int, int>> dq;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> L;
  for(int i = 0; i < N; i++)
  {
    std::cin >> val;
    if(dq.size() && dq.front().second + L <= i)
      dq.pop_front();
    while(dq.size() && dq.back().first > val)
      dq.pop_back();
    dq.push_back({val, i});
    std::cout << dq.front().first << ' ';
  }
  return 0;
}