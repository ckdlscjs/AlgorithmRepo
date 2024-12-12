#include <bits/stdc++.h>
using namespace std;
long long int N, M, val;
std::priority_queue<long long int, std::vector<long long int>, std::greater<long long int>> pq;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < N; i++)
  {
    std::cin >> val;
    pq.push(val);
  }
  for(int i = 0; i < M; i++)
  {
    long long int sum = 0;
    sum += pq.top();
    pq.pop();
    sum += pq.top();
    pq.pop();
    pq.push(sum);
    pq.push(sum);
  }
  long long int sum = 0;
  for(int i = 0; i < N; i++)
  {
    sum += pq.top();
    pq.pop();
  }
  std::cout << sum;
  return 0;
}