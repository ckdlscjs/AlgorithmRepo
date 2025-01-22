#include <bits/stdc++.h>
int N, val;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq_low;
std::priority_queue<int, std::vector<int>, std::less<int>> pq_high;
//low high(root) low(root) high
// <<<<<<<<<<<<<<<<<<<<<<<<<<
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 0; n < N; n++)
  {
    std::cin >> val;
    if(pq_high.size() <= pq_low.size())
      pq_high.push(val);
    else
      pq_low.push(val);
    if(pq_high.size() && pq_low.size() && pq_low.top() <= pq_high.top())
    {
      int ph_top = pq_high.top(); pq_high.pop();
      int pl_top = pq_low.top(); pq_low.pop();
      pq_high.push(pl_top);
      pq_low.push(ph_top);
    }
    std::cout << pq_high.top() << '\n';
  }
  return 0;
}