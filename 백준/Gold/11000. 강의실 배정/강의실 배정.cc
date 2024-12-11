#include <bits/stdc++.h>
using namespace std;
int N, a, b, res;
std::vector<std::pair<int, int>> inputs;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> a >> b;
    inputs.push_back({a, b});
  }
  std::sort(inputs.begin(), inputs.end());
  for(int i = 0; i < N; i++)
  {
    if(pq.size())
    {
      if(pq.top() <= inputs[i].first)
      {
        pq.pop();
        pq.push(inputs[i].second);
      }
      else
      {
        pq.push(inputs[i].second);
      }
    }
    else
    {
      pq.push(inputs[i].second);
    }
    res = std::max(res, (int)pq.size());
  }
  std::cout << res;
  return 0;
}