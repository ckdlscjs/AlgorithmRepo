#include <bits/stdc++.h>
using namespace std;
int n, w, L, cl, cw, l, arr[1005], cur = 1, idx = 0;

int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> w >> L;
  for(int i = 0; i < n; i++) std::cin >> arr[i];
  std::queue<std::pair<int, int>> q;
  while(cur)
  {
    while(q.size() && q.front().first <= cur)
    {
      cl -= q.front().second;
      cw--;
      q.pop();
    }
    if(q.empty() && idx >= n)
      break;
    if(idx < n && cw + 1 <= w && cl + arr[idx] <= L)
    {
      q.push({cur+w, arr[idx]});
      cl += arr[idx++];
      cw++;
    }
    cur++;
  }
  std::cout << cur;
  return 0;
}