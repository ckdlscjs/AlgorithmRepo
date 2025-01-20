#include <bits/stdc++.h>
int N, M, P, L;
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> pq_large;
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq_small;
bool nums[100'005];
std::string order;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 0; n < N; n++)
  {
    std::cin >> P >> L;
    pq_large.push({L, P});
    pq_small.push({L, P});
    nums[P] = true;
  }
  std::cin >> M;
  for(int m = 0; m < M; m++)
  {
    std::cin >> order;
    if(order == "recommend")
    {
      std::cin >> P;
      if(P == 1)
      {
        while(!nums[pq_large.top().second]) pq_large.pop();
        std::cout << pq_large.top().second << '\n';
      }
      else
      {
        while(!nums[pq_small.top().second]) pq_small.pop();
        std::cout << pq_small.top().second << '\n';
      }
    }
    else if(order == "solved")
    {
      std::cin >> P;
      nums[P] = false;
      while(!nums[pq_large.top().second]) pq_large.pop();
      while(!nums[pq_small.top().second]) pq_small.pop();
    }
    else
    {
      std::cin >> P >> L;
      pq_large.push({L, P});
      pq_small.push({L, P});
      nums[P] = true;
    }
  }
  return 0;
}