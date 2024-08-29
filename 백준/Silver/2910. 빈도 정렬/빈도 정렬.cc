#include <bits/stdc++.h>
using namespace std;
std::unordered_map<int, int> orders;
std::unordered_map<int, int> inputs;
struct compare
{
  bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b)
  {
    return a.first == b.first ? orders[a.second] > orders[b.second] : a.first < b.first;
  }
};
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n, c;
  std::cin >> n >> c;
  
  for(int i = 0; i < n; i++)
  {
    int input;
    std::cin >> input;
    inputs[input]++;
    if(orders.find(input) == orders.end())
      orders[input] = i;
  }
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, compare> pq;
  for(const auto& iter : inputs)
  {
    pq.push({iter.second, iter.first});
  }
    
  while(pq.size())
  {
    for(int i = 0; i < pq.top().first; i++)
    {
      std::cout << pq.top().second << ' ';
    }
    pq.pop();
  }
  return 0;
}