#include <bits/stdc++.h>
int N, val;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  std::stack<int> st;
  int start = 1;
  std::vector<char> ans;
  for(int i = 0; i < N; i++)
  {
    std::cin >> val;
    while(start <= val)
    {
      st.push(start++);
      ans.push_back('+');
    }
    if(st.top() == val)
    {
      st.pop();
      ans.push_back('-');
    }
    else
    {
      break;
    }
  }
  if(st.size() || start != N+1)
  {
    std::cout << "NO";
    return 0;
  }
  for(const auto& iter : ans)
    std::cout << iter <<'\n';
  return 0;
}