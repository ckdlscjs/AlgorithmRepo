#include <bits/stdc++.h>
int n, order, input;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  std::stack<int> st;
  for(int i = 0; i < n; i++)
  {
    std::cin >> order;
    if(order == 1)
    {
      std::cin >> input;
      st.push(input);
    }
    else if(order == 2)
    {
      if(st.size())
      {
        std::cout << st.top() << '\n';
        st.pop();
      }
      else
        std::cout << -1 <<'\n';
    }
    else if(order == 3)
    {
      std::cout << st.size() <<'\n';
    }
    else if(order == 4)
    {
      std::cout << (st.empty() ? 1 : 0) << '\n';
    }
    else if(order == 5)
    {
      std::cout << (st.size() ? st.top() : -1) << '\n';
    }
  }
  return 0;
}