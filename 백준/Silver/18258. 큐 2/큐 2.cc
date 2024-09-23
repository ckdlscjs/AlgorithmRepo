#include <bits/stdc++.h>
int n, input;
std::string order;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  std::queue<int> q;
  for(int i = 0; i < n; i++)
  {
    std::cin >> order;
    if(order == "push")
    {
      std::cin >> input;
      q.push(input);
    }
    else if(order == "pop")
    {
      if(q.empty())
      {
        std::cout << -1 <<'\n';
        continue;
      }
      std::cout << q.front() <<'\n';
      q.pop();
    }
    else if(order == "size")
    {
      std::cout << q.size() <<'\n';
    }
    else if(order == "empty")
    {
      std::cout << (q.empty() ? 1 : 0) <<'\n';
    }
    else if(order == "front")
    {
      std::cout << (q.empty() ? -1 : q.front()) <<'\n';
    }
    else if(order == "back")
    {
     std::cout << (q.empty() ? -1 : q.back()) <<'\n';
    }
  }
  return 0;
}