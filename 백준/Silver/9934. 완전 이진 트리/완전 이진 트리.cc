#include <bits/stdc++.h>
using namespace std;
int k;
const int MaxN = 1050;
int arr[MaxN];
void LDR(int idx, int depth)
{
  if(depth >= k)
    return;
  LDR(idx*2, depth+1);
  std::cin >> arr[idx];
  LDR(idx*2 + 1, depth+1);
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> k;
  LDR(1, 0);
  int depth = 0;
  int idx = 1;
  while(depth < k)
  {
    int range = idx + (1 << depth);
    for(idx; idx < range; idx++)
      std::cout << arr[idx] << ' ';
    std::cout << '\n';
    depth++;
  }
  return 0;
}