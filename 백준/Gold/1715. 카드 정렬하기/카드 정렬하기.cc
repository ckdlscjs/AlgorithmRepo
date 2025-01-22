#include <bits/stdc++.h>
int N, input, res;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 0; n < N; n++)
  {
    std::cin >> input;
    pq.push(input);
  }
  while(pq.size() > 1)
  {
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    res += a + b;
    pq.push(a+b);
  }
  std::cout << res;
  return 0;
}