#include <bits/stdc++.h>
int n;
std::pair<int, int> pd[10005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for(int i = 0; i < n; i++)
      std::cin >> pd[i].first >> pd[i].second;
    std::sort(pd, pd+n, [](const std::pair<int, int>& a, const std::pair<int, int>& b){
      return a.second < b.second;
    });
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    long long int sum = 0;
    for(int i = 0; i < n; i++)
    {
      pq.push(pd[i].first);
      if(pq.size() > pd[i].second)
        pq.pop();
    }
    while(pq.size())
    {
      sum += pq.top();
      pq.pop();
    }
    std::cout << sum;
    return 0;
}