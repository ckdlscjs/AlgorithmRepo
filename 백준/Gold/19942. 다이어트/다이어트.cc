#include <bits/stdc++.h>
using namespace std;
int n;
const int MaxN = 20;
int chk[4];
int arr[MaxN][5];
struct compare
{
  bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b)
  {
    if(a.first == b.first)
    {
      std::vector<int> res_a;
      std::vector<int> res_b;
      for(int i = 0; i < n; i++)
      {
        if(a.second & (1 << i))
          res_a.push_back(i+1);
        if(b.second & (1 << i))
          res_b.push_back(i+1);
      }
      int len = std::min(res_a.size(), res_b.size());
      for(int i = 0; i < len; i++)
      {
        if(res_a[i] == res_b[i])
          continue;
        return res_a[i] > res_b[i];
      }
      return res_a.size() > res_b.size();
    }
    return a.first > b.first;
  }
};
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, compare> pq;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  std::cin >> chk[0] >> chk[1] >> chk[2] >> chk[3];
  for(int i = 0; i < n; i++)
    std::cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4];
  
  for(int i = 0; i < (1 << n); i++)
  {
    int sums[5];
    std::memset(sums, 0, sizeof(sums));
    for(int j = 0; j < n; j++)
    {
      if(i & (1<<j))
      {
        for(int k = 0; k < 5; k++)
          sums[k] += arr[j][k];
      }
    }
    if(sums[0] >= chk[0] && sums[1] >= chk[1]  && sums[2] >= chk[2] && sums[3] >= chk[3])
    {
      pq.push({sums[4], i});
    }
  }
  if(pq.empty())
  {
    std::cout << -1;
    return 0;
  }
  std::cout << pq.top().first << '\n';
  for(int i = 0; i < n; i++)
  {
    if(pq.top().second & (1 << i))
      std::cout << i+1 << ' ';
  }
  return 0;
}