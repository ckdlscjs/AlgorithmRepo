#include <bits/stdc++.h>
int n;
struct comp
{
  bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b)
  {
      return a.second == b.second ? a.first > b.first : a.second > b.second;
  }
};
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comp> pq;
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        pq.push({a, b});
    }
    while(pq.size())
    {
        std::pair<int, int> cur = pq.top();
        pq.pop();
        std::cout <<cur.first << ' ' << cur.second << '\n';
    }
    return 0;
}