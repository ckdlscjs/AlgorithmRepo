#include <bits/stdc++.h>
using namespace std;
int N, len, lis[100'005], idxs[100'005];
std::stack<int> st;
std::pair<int, int> inputs[100'005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
    std::cin >> inputs[i].first >> inputs[i].second;
  std::sort(inputs, inputs+N, [](const std::pair<int, int>& a, const std::pair<int, int>& b)
  {
    return a.first < b.first;
  });
  for(int i = 0; i < N; i++)
  {
    if(i == 0 || inputs[lis[len-1]].second < inputs[i].second)
    {
      idxs[i] = len;
      lis[len++] = i;
    }
    else
    {
      int lo = -1, hi = len;
      while(lo + 1 < hi)
      {
        int mid = (lo + hi) / 2;
        if(inputs[i].second <= inputs[lis[mid]].second) hi = mid;
        else lo = mid;
      }
      idxs[i] = hi;
      lis[hi] = i;
    }
  }
  len--;
  for(int i = N-1; i >= 0; i--)
    if(idxs[i] == len)
      len--;
    else
      st.push(i);
  std::cout << st.size() << '\n';
  while(st.size())
  {
    std::cout << inputs[st.top()].first << '\n';
    st.pop();
  }
  return 0;
}