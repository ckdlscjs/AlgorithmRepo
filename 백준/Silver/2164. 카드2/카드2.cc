#include <bits/stdc++.h>
int n;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  std::deque<int> dq;
  for(int i = 1; i <= n; i++)
    dq.push_back(i);
  while(dq.size() > 1)
  {
    dq.pop_front();
    dq.push_back(dq.front());
    dq.pop_front();
  }
  std::cout << dq.front();
  return 0;
}