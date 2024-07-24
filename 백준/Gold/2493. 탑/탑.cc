#include <bits/stdc++.h>
using namespace std;
std::stack<std::pair<int, int>> st;
int n;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  for(int i = 1; i <= n; i++)
  {
    int height;
    std::cin >> height;
    while(st.size() && st.top().first < height)
      st.pop();
    std::cout << (st.empty() ? 0 : st.top().second) <<' ';
    st.push({height, i});
  }
  return 0;
}