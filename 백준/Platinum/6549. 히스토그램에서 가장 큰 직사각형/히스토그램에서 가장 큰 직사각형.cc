#include <bits/stdc++.h>
int n, arr[100'005];
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  while(std::cin >> n && n)
  {
    long long int maxrec = 0;
    for(int i = 0; i < n; i++)
      std::cin >> arr[i];
    arr[n] = 0;
    std::stack<int> st;
    for(int i = 0; i <= n; i++)
    {
      while(st.size() && arr[st.top()] > arr[i])
      {
        int height = arr[st.top()];
        st.pop();
        int width = st.empty() ? i : i - st.top() - 1;
        maxrec = std::max(maxrec, (long long int)width*height);
      }
      st.push(i);
    }
    std::cout << maxrec << '\n';
  }
  return 0;
}