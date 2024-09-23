#include <bits/stdc++.h>
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::string str;
  std::cin >> str;
  std::unordered_map<char, int> orders;
  orders['('] = 3;
  orders[')'] = 3;
  orders['*'] = 2;
  orders['/'] = 2;
  orders['+'] = 1;
  orders['-'] = 1;
  std::stack<char> st;
  for(const auto& iter : str)
  {
    if('A' <= iter && iter<= 'Z')
    {
      std::cout << iter;
    }
    else if(st.empty() || iter == '(')
    {
      st.push(iter);
    }
    else if(iter == ')')
    {
      while(orders[st.top()] < orders[iter])
      {
        std::cout << st.top();
        st.pop();
      }
      st.pop();
    }
    else
    {
      while(st.size() && orders[st.top()] >= orders[iter])
      {
        if(st.top() == '(')
          break;
        std::cout << st.top();
        st.pop();
      }
      st.push(iter);
    }
  }
  while(st.size())
  {
    std::cout << st.top();
    st.pop();
  }
  return 0;
}