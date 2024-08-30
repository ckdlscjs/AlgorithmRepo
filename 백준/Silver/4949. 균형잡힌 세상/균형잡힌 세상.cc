#include <bits/stdc++.h>
using namespace std;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::string str;
  while(std::getline(std::cin, str) && str != ".")
  {
    std::stack<char> st;
    for(const auto& iter : str)
    {
      if(iter == '(')
        st.push(iter);
      else if(iter == '[')
        st.push(iter);
      else if(iter == ')')
      {
        if(st.size() && st.top() == '(')
          st.pop();
        else
          st.push(iter);
      }
       else if(iter == ']')
      {
        if(st.size() && st.top() == '[')
          st.pop();
        else
          st.push(iter);
      }
    }
    std::cout << (st.empty() ? "yes" : "no") <<'\n';
  }
  return 0;
}