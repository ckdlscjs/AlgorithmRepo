#include <bits/stdc++.h>
int N;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  std::queue<int> q;
  for(int i = 1; i <= N; i++)
    q.push(i);
  while(q.size() != 1)
  {
    q.pop();
    q.push(q.front());
    q.pop();
  }
  std::cout << q.front();
  return 0;
}