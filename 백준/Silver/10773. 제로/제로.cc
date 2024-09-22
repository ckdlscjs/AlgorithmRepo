#include <bits/stdc++.h>
int k;
std::stack<int> st;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> k;
  for(int i = 0; i < k; i++)
  {
    int num;
    std::cin >> num;
    if(num == 0)
      st.pop();
    else
      st.push(num);
  }
  int sum = 0;
  while(st.size())
  {
    sum += st.top();
    st.pop();
  }
  std::cout << sum;
  return 0;
}