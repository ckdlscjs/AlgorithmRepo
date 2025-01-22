#include <bits/stdc++.h>
long long int T, N, input;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  for(int t = 0; t < T; t++)
  {
    long long int res = 0;
    std::priority_queue<long long int, std::vector<long long int>, std::greater<long long int>> pq;
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
      std::cin >> input;
      pq.push(input);
    }
    while(pq.size() > 1)
    {
      long long int a = pq.top(); pq.pop();
      long long int b = pq.top(); pq.pop();
      res += a + b;
      pq.push(a+b);
    }
    std::cout << res << '\n';
  }
  
  return 0;
}