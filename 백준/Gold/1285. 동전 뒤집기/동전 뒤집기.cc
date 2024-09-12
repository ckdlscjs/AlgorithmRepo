#include <bits/stdc++.h>
using namespace std;

int n;
int arrs[21];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  for(int i = 0; i < n; i++)
  {
    std::string str;
    std::cin >> str;
    for(int j = 0; j < str.size(); j++)
      if(str[j] == 'T') arrs[i] |= 1 << j;
  }
    
  int res = 987654321;
  for(int hori = 0; hori < (1 << n); hori++)
  {
    int cnt_t = 0;
    for(int j = 1; j < (1 << n); j *= 2)
    {
      int temp_t = 0;
      for(int i = 0; i < n; i++)
      {
        temp_t += (hori & (1 << i) ? ~arrs[i] : arrs[i]) & j ? 1 : 0;
      }
      cnt_t += temp_t > n/2 ? n-temp_t : temp_t;
    }
    res = std::min(res, cnt_t);
  }
  std::cout << res;
  return 0;
}