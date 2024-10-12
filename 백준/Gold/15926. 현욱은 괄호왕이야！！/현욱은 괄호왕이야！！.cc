#include <bits/stdc++.h>
int n, res;
std::string str;
std::stack<int> st;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); 
  std::cout.tie(0);
  std::cin >> n;
  std::cin >> str;
  st.push(-1);
  for(int i = 0; i < n; i++)
  {
    if(str[i] == '(') st.push(i);  
    else
    {
      st.pop();
      if(!st.empty()) res = std::max(res, i - st.top());
      else st.push(i);
    }
  }
  std::cout << res;
  return 0;
}