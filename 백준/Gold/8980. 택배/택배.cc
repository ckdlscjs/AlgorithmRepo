#include <bits/stdc++.h>
int N, C, M, u, v, c, capacity[2'005], res;
std::vector<std::pair<std::pair<int, int>,int>> arr;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> C >> M;
  for(int i = 0; i < M; i++)
  {
    std::cin >> u >> v >> c;
    arr.push_back({{u, v}, c});
  }
  std::sort(arr.begin(), arr.end(), [](const std::pair<std::pair<int, int>,int>& a, const std::pair<std::pair<int, int>,int>& b){
    return a.first.second == b.first.second ? a.first.first < b.first.first : a.first.second < b.first.second;
  });
  for(int i = 0; i < M; i++)
  {
    int u = arr[i].first.first;
    int v = arr[i].first.second;
    int c = arr[i].second;
    int maxCapacity = 0;
    for(int j = u; j < v; j++)
      maxCapacity = std::max(maxCapacity, capacity[j]);
    int val = std::min(c, C-maxCapacity);
    res += val;
    for(int j = u; j < v; j++)
      capacity[j] += val;
  }
  std::cout << res;
  return 0;
}