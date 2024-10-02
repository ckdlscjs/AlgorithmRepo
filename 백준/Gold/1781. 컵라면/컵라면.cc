#include <bits/stdc++.h>
int n, sum;
std::pair<int, int> arr[200005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
      std::cin >> arr[i].first >> arr[i].second;
      sum += arr[i].second;
    }
      
    std::sort(arr, arr+n, std::less<>());
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for(int i = 0; i < n; i++)
    {
      pq.push(arr[i].second);
      if(pq.size() > arr[i].first)
      {
        sum -= pq.top();
        pq.pop();
      }
    }
    std::cout << sum;
    return 0;
}