#include <bits/stdc++.h>
int arr[250'005];
int N, M, B;
struct comp
{
  bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b)
  {
    return a.first == b.first ? a.second < b.second : a.first > b.first;
  }
};
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M >> B;
  for(int i = 0; i < N*M; i++) std::cin >> arr[i];
  std::sort(arr, arr+N*M, std::greater<>());
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comp> pq;
  for(int height = 0; height <= 256; height++)
  {
    int inven = B, t = 0, amount = 0;
    for(int i = 0; i < N*M; i++)
    {
      if(height == arr[i]) continue;
      if(arr[i] > height)
      {
        amount = arr[i] - height;
        t += amount * 2;
        inven += amount;
      }
      else
      {
        amount = height - arr[i];
        if(amount > inven)
        {
          t = -1;
          break;
        }
        t += amount;
        inven -= amount;
      }
    }
    if(t >= 0)
      pq.push({t, height});
  }
  std::cout << pq.top().first << ' ' << pq.top().second;
  return 0;
}