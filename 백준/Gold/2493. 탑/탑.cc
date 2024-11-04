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
  std::vector<int> answer(N, 0);
  for(int i = 0; i < N; i++)
  {
    std::cin >> height;
    if(st.empty())
    {
      st.push({height, i+1});
    }
    else
    {
      if(st.top().first >= height)
      {
        answer[i] = st.top().second;
      }
      while(st.size() && st.top().first < height)
      {
        st.pop();
      }
      if(st.size())
        answer[i] = st.top().second;
      st.push({height, i+1});
    }
  }
  for(const auto& iter : answer)
    std::cout << iter << ' ';
  
  return 0;
}