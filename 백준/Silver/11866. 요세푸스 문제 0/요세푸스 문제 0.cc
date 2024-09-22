#include <bits/stdc++.h>
int n, k;
std::deque<int> dq;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> k;
  for(int i = 1; i <= n; i++)
    dq.push_back(i);
  int cnt = 0;
  std::vector<int> res;
  while(dq.size())
  {
    int front = dq.front();
    dq.pop_front();
    cnt++;
    if(!(cnt%k))
    {
      res.push_back(front);
    }
    else
    {
      dq.push_back(front);
    }
  }
  std::cout <<'<';
  for(int i = 0; i < res.size()-1; i++)
    std::cout << res[i] << ", ";
  std::cout << res[res.size()-1] << '>';
  return 0;
}