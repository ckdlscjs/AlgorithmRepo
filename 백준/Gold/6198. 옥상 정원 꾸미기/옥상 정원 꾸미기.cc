#include <bits/stdc++.h>
int N, val;
long long int sum = 0;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  std::stack<int> st;
  for(int i = 0; i < N; i++)
  {
    std::cin >> val;
    while(st.size() && st.top() <= val)
      st.pop();
    sum += st.size();
    st.push(val);
  }
  std::cout << sum;
  return 0;
}