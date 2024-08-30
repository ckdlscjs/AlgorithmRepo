#include <bits/stdc++.h>
using namespace std;
int h, w;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> h >> w;
  for(int i = 0; i < h; i++)
  {
    int res = -1;
    for(int j = 0; j < w; j++)
    {
      char input;
      std::cin >> input;
      if(input == 'c')
      {
        res = 0;
      }
      else
      {
        if(res >= 0)
          res++;
      }
      std::cout << res << ' ';
    }
    std::cout <<'\n';
  }
  return 0;
}