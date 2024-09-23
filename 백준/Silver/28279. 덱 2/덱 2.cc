#include <bits/stdc++.h>
int n, order, input;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  std::deque<int> dq;
  for(int i = 0; i < n; i++)
  {
    std::cin >> order;
    if(order == 1)
    {
      std::cin >> input;
      dq.push_front(input);
    }
    else if(order == 2)
    {
      std::cin >> input;
      dq.push_back(input);
    }
    else if(order == 3)
    {
      if(dq.size())
      {
        std::cout << dq.front()<<'\n';
        dq.pop_front();
      }
      else
        std::cout <<-1<<'\n';
    }
    else if(order == 4)
    {
      if(dq.size())
      {
        std::cout << dq.back()<<'\n';
        dq.pop_back();
      }
      else
        std::cout <<-1<<'\n';
    }
    else if(order == 5)
    {
      std::cout << dq.size() <<'\n';
    }
    else if(order == 6)
    {
      std::cout << (dq.empty() ? 1 : 0) <<'\n';
    }
     else if(order == 7)
    {
      if(dq.size())
      {
        std::cout << dq.front()<<'\n';
      }
      else
        std::cout <<-1<<'\n';
    }
    else if(order == 8)
    {
      if(dq.size())
      {
        std::cout << dq.back()<<'\n';
      }
      else
        std::cout <<-1<<'\n';
    }
  }
  return 0;
}