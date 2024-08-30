#include <bits/stdc++.h>
using namespace std;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  for(int i = 0; i < n; i++)
  {
    std::string str;
    std::cin >> str;
    std::stack<char> st;
    bool chk = true;
    for(const auto& iter : str)
    {
      if(iter == '(')
        st.push(iter);
      else
      {
        if(st.size()) 
          st.pop();
        else
        {
          chk = false;
          break;
        }
      }
    }
    std::cout << (st.empty() && chk ? "YES" : "NO") << '\n';
  }
  return 0;
}