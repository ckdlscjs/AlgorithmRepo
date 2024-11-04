#include <bits/stdc++.h>
int N;
int height;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  std::stack<std::pair<int, int>> st;
  for(int i = 1; i <= N; i++)
  {
    std::cin >> height;
    while(st.size() && st.top().first < height) st.pop();
    std::cout << (st.size() ? st.top().second : 0) << ' ';
    st.push({height, i});
  }
  return 0;
}