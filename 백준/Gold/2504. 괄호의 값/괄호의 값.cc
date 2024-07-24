#include <bits/stdc++.h>
using namespace std;
std::stack<int> st;
int main() {
  std::string str;
  std::cin >> str;
  if(str.size() % 2)
  {
    std::cout << 0;
    return 0;
  }
  for(const auto iter : str)
  {
    if(st.empty() && (iter == ')' || iter ==']'))
    {
      std::cout << 0;
      return 0;
    }
    if(st.size() && st.top() == '(' && iter == ']')
    {
      std::cout << 0;
      return 0;
    }
    if(st.size() && st.top() == '[' && iter == ')')
    {
      std::cout << 0;
      return 0;
    }
    if(iter == '(' || iter == '[')
    {
      st.push(iter);
      continue;
    }
    int num = 0;
    if(st.size() && st.top() == '(' && iter == ')')
    {
      num = 2;
      st.pop();
      while(st.size() && st.top() != '(' && st.top() != '[')
      {
        num += st.top();
        st.pop();
      }
      st.push(num);
    }
    else if(st.size() && st.top() == '[' && iter == ']')
    {
      num = 3;
      st.pop();
      while(st.size() && st.top() != '(' && st.top() != '[')
      {
        num += st.top();
        st.pop();
      }
      st.push(num);
    }
    else
    {
      num = st.top();
      st.pop();
      if(st.size() &&  st.top() == '(' && iter == ')')
      {
        num *= 2;
        st.pop();
      }
      else if(st.size() &&  st.top() == '[' && iter == ']')
      {
        num *= 3;
        st.pop();
      }
      while(st.size() && st.top() != '(' && st.top() != '[')
      {
        num += st.top();
        st.pop();
      }
      st.push(num);
    }
  }
  if(st.size() != 1)
    std::cout << 0;
  else
    std::cout << st.top();
  return 0;
}