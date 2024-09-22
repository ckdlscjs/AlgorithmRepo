#include <bits/stdc++.h>
int n;
std::deque<std::pair<int,int>> dq;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  for(int i = 1; i <= n; i++)
  {
    int input;
    std::cin >> input;
    dq.push_back({i, input});
  }
  std::vector<int> ret;
  ret.push_back(1);
  int cnt = dq.front().second;
  dq.pop_front();
  while(dq.size())
  {
    std::pair<int, int> cur;
    if(cnt > 0)
    {
      for(int i = 0; i < cnt - 1; i++)
      {
        cur = dq.front();
        dq.push_back(cur);
        dq.pop_front();
      }
      cur = dq.front();
      dq.pop_front();
    }
    else if(cnt < 0)
    {
      for(int i = 0; i < std::abs(cnt) - 1; i++)
      {
        cur = dq.back();
        dq.push_front(cur);
        dq.pop_back();
      }
      cur = dq.back();
      dq.pop_back();
    }
    cnt = cur.second;
    ret.push_back(cur.first);
  }
  for(const auto& iter : ret)
  {
    std::cout << iter << ' ';
  }
  return 0;
}