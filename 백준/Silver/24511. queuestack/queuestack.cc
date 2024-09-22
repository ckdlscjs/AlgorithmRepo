#include <bits/stdc++.h>
int n, m;
const int MaxN = 100005;
bool IsStack[MaxN];
std::deque<int> dq;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  for(int i = 0; i < n; i++)
    std::cin >> IsStack[i];
  for(int i = 0; i < n; i++)
  {
    int input;
    std::cin >> input;
    if(IsStack[i])
      continue;
    dq.push_front(input);
  }
  std::cin >> m;
  std::vector<int> ret;
  for(int i = 0; i < m; i++)
  {
    int input;
    std::cin >> input;
    dq.push_back(input);
    ret.push_back(dq.front());
    dq.pop_front();
    
  }
  for(const auto& iter : ret)
    std::cout << iter << ' ';
  return 0;
}