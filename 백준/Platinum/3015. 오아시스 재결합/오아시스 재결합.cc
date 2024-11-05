#include <bits/stdc++.h>
long long int N, sum, val;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  std::stack<std::pair<int, long long int>> st;
  for(int i = 0; i < N; i++)
  {
    std::cin >> val;
    long long int cnt = 1;
    while(st.size() && st.top().first <= val)
    {
      sum += st.top().second;
      if(st.top().first == val) cnt = st.top().second + 1;
      st.pop();
    }
    if(st.size()) sum++;
    st.push({val, cnt});
  }
  std::cout << sum;
  return 0;
}