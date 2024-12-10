#include <bits/stdc++.h>
using namespace std;
int N, res;
std::pair<int, int> st, s;
std::pair<int, int> en, e;
std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> inputs;
struct comp
{
  bool operator()(const std::pair<std::pair<int, int>, std::pair<int, int>>& a, const std::pair<std::pair<int, int>, std::pair<int, int>>& b)
  {
    return a.second.first == b.second.first ? a.second.second < b.second.second : a.second.first < b.second.first;
  }
};
std::priority_queue<std::pair<std::pair<int, int>, std::pair<int, int>>, std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>, comp> pq;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  st = std::make_pair(3, 1);
  en = std::make_pair(3, 1);
  for(int i = 0; i < N; i++)
  {
    std::cin >> s.first >> s.second >> e.first >> e.second;
    inputs.push_back({s, e});
  }
  std::sort(inputs.begin(), inputs.end(), [](const std::pair<std::pair<int, int>, std::pair<int, int>>& a, const std::pair<std::pair<int, int>, std::pair<int, int>>& b){
    return (a.first.first == b.first.first ? a.first.second < b.first.second : a.first.first < b.first.first);
  });
  
  for(const auto& iter : inputs)
  {
    //std::cout << iter.first.first << ' ' << iter.first.second << ' ' << iter.second.first << ' '<<iter.second.second << '\n';
    if(iter.first.first < en.first || (iter.first.first == en.first && iter.first.second <= en.second))
      pq.push(iter);
    else
    {
      if(pq.size())
      {
        st = pq.top().first;
        en = pq.top().second;
        res++;
        while(pq.size())
          pq.pop();
        if(iter.first.first < en.first || (iter.first.first == en.first && iter.first.second <= en.second))
          pq.push(iter);
      }
      else
      {
        res = 0;
        break;
      }
    }
  }
  if(res && en.first <= 11 && en.second <= 30)
  {
    if(pq.top().second.first <= 11 && pq.top().second.second <= 30)
      res = 0;
    else
      res++;
  }
    
  std::cout << res;
  return 0;
}