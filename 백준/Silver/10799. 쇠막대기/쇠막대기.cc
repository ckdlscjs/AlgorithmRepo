#include <bits/stdc++.h>
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::string str;
  std::cin >> str;
  std::stack<char> st;
  int ans = 0;
  char ch;
  for(const auto& iter : str)
  {
    if(iter == '(')
    {
      st.push('(');
    }
    else
    {
      st.pop();
      if(ch == '(' && st.size())
        ans += st.size();
      else if(ch == ')')
        ans += 1;
    }
    ch = iter;
  }
  std::cout << ans;
  return 0;
}