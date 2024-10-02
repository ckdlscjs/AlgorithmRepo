#include <bits/stdc++.h>
long long int n, k, c, sum;
std::pair<int, int> jewels[300'005];
int bags[300'005];
std::priority_queue<int, std::vector<int>, std::less<int>> pq;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n >> k;
    for(int i = 0; i < n; i++)
      std::cin >> jewels[i].first >> jewels[i].second;
    std::sort(jewels, jewels+n, std::less<>());
    for(int i = 0; i < k; i++)
      std::cin >> bags[i];
    std::sort(bags, bags+k, std::less<>());
    
    int jidx = 0;
    for(int i = 0; i < k; i++)
    {
      while(jidx < n && jewels[jidx].first <= bags[i]) pq.push(jewels[jidx++].second);
      if(pq.size())
      {
        sum += pq.top();
        pq.pop();
      }
    }
    std::cout << sum;
    return 0;
}