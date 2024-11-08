#include <bits/stdc++.h>
int N, arr[500'005], sum, maxcnt;
std::map<int, int> cnts;
std::priority_queue<int, std::vector<int>, std::greater<int>>pq;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> arr[i];
    cnts[arr[i]]++;
    sum += arr[i];
    maxcnt = std::max(maxcnt, cnts[arr[i]]);
  }
  std::cout << (int)std::round(sum / (double)N) << '\n';
  std::sort(arr, arr+N, std::less<>());
  std::cout << arr[N/2] << '\n';
  for(const auto& iter : cnts)
    if(iter.second == maxcnt)
      pq.push(iter.first);
  if(pq.size() >= 2)
    pq.pop();
  std::cout << pq.top() << '\n';
  std::cout << arr[N-1] - arr[0];
  return 0;
}