#include <bits/stdc++.h>
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::string str;
  std::cin >> str;
  std::stack<std::string> st;
  int ans = 0;
  bool chk = true;
  if(str.size() % 2)
  {
    std::cout << ans;
    return 0;
  }
  for(const auto& iter : str)
  {
    if(iter == '(' || iter == '[')
    {
      st.push(std::string(1, iter));
    }
    else
    {
      int amount = (iter == ']' ? 3 : 2);
      int cur = 0;
      while(st.size() && !(st.top() == "(" || st.top() == "["))
      {
        cur += std::stoi(st.top());
        st.pop();
      }
      if(st.empty() || (st.top() == "[" && iter == ')') ||(st.top()== "(" && iter == ']'))
      {
        chk = false;
        break;
      }
      st.pop();
      st.push(std::to_string(cur ? amount*cur : amount));
    }
  }
  if(!chk)
  {
    std::cout << ans;
    return 0;
  }
  while(st.size())
  {
    if(st.top() == "(" || st.top() == "[")
    {
      ans = 0;
      break;
    }
    ans += std::stoi(st.top()), st.pop();
  }
  std::cout << ans;
  return 0;
}