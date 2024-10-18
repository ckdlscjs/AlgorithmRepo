#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1'000'005;
int arr[MaxN];
int idxs[MaxN];
int lis[MaxN];
int N, lidx;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> arr[i];
    if(i == 0 || lis[lidx-1] < arr[i])
    {
      idxs[i] = lidx;
      lis[lidx++] = arr[i];
    }
    else
    {
      int lo = -1, hi = lidx;
      while(lo + 1 < hi)
      {
        int mid = (lo + hi) / 2;
        if(lis[mid] >= arr[i]) hi = mid;
        else lo = mid;
      }
      idxs[i] = hi;
      lis[hi] = arr[i];
    }
  }
  std::cout << lidx << '\n';
  lidx--;
  std::stack<int> st;
  for(int i = N-1; i >= 0; i--)
  {
    if(idxs[i] == lidx)
    {
      st.push(arr[i]);
      lidx--;
      if(lidx < 0)
        break;
    }
  }
  while(st.size())
  {
    std::cout << st.top() << ' ';
    st.pop();
  }
  return 0;
}