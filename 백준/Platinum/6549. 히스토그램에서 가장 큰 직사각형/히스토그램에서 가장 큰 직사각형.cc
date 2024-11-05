#include <bits/stdc++.h>
int n;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  while(std::cin >> n && n)
  {
    long long int maxrec = 0, val = 0;
    std::stack<std::pair<long long int, long long int>> st;
    for(int i = 0; i < n; i++)
    {
      std::cin >> val;
      while(st.size() && st.top().first > val)
      {
        long long int height = st.top().first;
        st.pop();
        long long int width = (st.empty() ? i : i - st.top().second - 1);
        maxrec = std::max(maxrec, height*width);
      }
      st.push({val, i});
    }
    st.push({0, n});
    while(st.size())
    {
      long long int height = st.top().first;
      st.pop();
      long long int width = (st.empty() ? n : n - st.top().second - 1);
      maxrec = std::max(maxrec, height*width);
    }
    std::cout << maxrec << '\n';
  }
  return 0;
}