#include <bits/stdc++.h>
using namespace std;
int n;
int quadtree[65][65];
std::string packing(int ly, int lx, int ry, int rx)
{
  if(ry == ly && rx == lx)
    return std::to_string(quadtree[ly][lx]);
  int midy = (ly + ry) / 2;
  int midx = (lx + rx) / 2;
  std::string r1 = packing(ly, lx, midy, midx);
  std::string r2 = packing(ly, midx+1, midy, rx);
  std::string r3 = packing(midy+1, lx, ry, midx);
  std::string r4 = packing(midy+1, midx+1, ry, rx);
  if(r1 == r2 && r2 == r3 && r3 == r4 && r4 == r1 && r1.size() == 1)
    return r1;
  else
    return "(" + r1 + r2 + r3 + r4+")";
}
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
    {
      quadtree[i][j] = str[j] - '0';
    }
  }
  std::cout << packing(0,0,n-1,n-1);
  return 0;
}