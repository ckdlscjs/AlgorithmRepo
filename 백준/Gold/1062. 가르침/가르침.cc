#include <bits/stdc++.h>
using namespace std;
const int MaxN = 55;
int n, k, strings[MaxN];

int Check(int idx, int cnt, int mask)
{
  if(cnt > k) return 0;
  if(idx >= 26)
  {
    int ret = 0;
    for(int i = 0; i < n; i++)
      ret += (strings[i] & mask) == strings[i] ? 1 : 0;
    return ret;
  }
  int ret = Check(idx+1, cnt+1, mask | (1 << idx));
  if(idx != 'a' - 'a' && idx != 'n' - 'a' && idx != 't'-'a' && idx != 'i' - 'a' && idx != 'c'-'a')
    ret = std::max(ret, Check(idx+1, cnt, mask));
  return ret;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> k;
  for(int i = 0; i < n; i++)
  {
    std::string str;
    std::cin >> str;
    for(const auto& iter : str)
      strings[i] |= 1 << (iter - 'a');
  }
  std::cout << Check(0, 0, 0);
  return 0;
}