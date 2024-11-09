#include <bits/stdc++.h>
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::string str;
  std::cin >> str;
  std::stack<char> st;
  int answer = 0, temp = 1;
  for(int i = 0; i < str.size(); i++)
  {
    if(str[i] == '(' || str[i] == '[')
    {
      temp *= (str[i] == '(' ? 2 : 3);
      st.push(str[i]);
    }
    else
    {
      if(st.empty() || (st.top() == '(' && str[i] == ']') || (st.top() == '[' && str[i] == ')'))
      {
        answer = 0;
        break;
      }
      else if((str[i-1] == '(' && str[i] == ')') || (str[i-1] == '[' && str[i] == ']'))
      {
        answer += temp;
        temp /= (str[i-1] == '(' ? 2 : 3);
        st.pop();
      }
      else
      {
        temp /= (str[i] == ')' ? 2 : 3);
        st.pop();
      }
    }
  }
  if(st.size()) answer = 0;
  std::cout << answer;
  return 0;
}