#include <bits/stdc++.h>
using namespace std;
int N, val;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> val;
    if(val == 0)
    {
      if(pq.empty())
      {
        std::cout << 0 <<'\n';
      }
      else
      {
        std::cout <<pq.top() << '\n';
        pq.pop();
      }
    }
    else
      pq.push(val);
  }
  return 0;
}