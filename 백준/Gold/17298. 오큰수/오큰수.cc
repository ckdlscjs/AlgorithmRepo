#include <bits/stdc++.h>
using namespace std;
int arr[1000005];
int result[1000005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  for(int i = 0; i < n; i++)
    std::cin >> arr[i];
  result[n-1] = -1;
  std::stack<int> st;
  st.push(arr[n-1]);
  for(int i = n-2; i >= 0; i--)
  {
    while(st.size() && arr[i] >= st.top())
      st.pop();
    result[i] = st.size() ? st.top() : -1;
    st.push(arr[i]);
  }
  for(int i = 0; i < n; i++)
    std::cout << result[i] << ' ';
  return 0;
}