#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for(int i = 0; i < 3; i++)
    {
      int val;
      std::cin >> val;
      pq.push(val);
    }
    while(pq.size())
      std::cout << pq.top() << ' ', pq.pop();
    return 0;
}