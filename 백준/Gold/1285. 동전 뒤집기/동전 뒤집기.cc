#include <bits/stdc++.h>
using namespace std;

int n;
std::string arrs[21][2];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  for(int i = 0; i < n; i++)
  {
    std::string str;
    std::cin>>str;
    std::string rev_str;
    for(int j = 0; j < str.size(); j++)
      rev_str += str[j] == 'T' ? 'H' : 'T';
    arrs[i][0] = str;
    arrs[i][1] = rev_str;
  }
  int res = 987654321;
  for(int hori = 0; hori < (1 << n); hori++)
  {
    int cnt_t = 0;
    for(int j = 0; j < n; j++)
    {
      int temp_t = 0;
      for(int i = 0; i < n; i++)
      {
        int rev = hori & (1 << i) ? 1 : 0;
        temp_t += arrs[i][rev][j] == 'T' ?  1 : 0;
      }
      cnt_t += temp_t > n/2 ? n-temp_t : temp_t;
      if(cnt_t > res) continue;
    }
    res = std::min(res, cnt_t);
  }
  std::cout << res;
  return 0;
}