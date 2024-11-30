#include <bits/stdc++.h>
using namespace std;
int N, M;
std::pair<int, int> Check(int n, int m, int y, int x, int dir)
{
  if(n <= 1) return {x, y};
  n /= 2;
  int area = n*n;
  if(dir == 0)
  {
    if(1 <= m && m <= area) return Check(n, m, y, x, 1);
    else if(area < m && m <= area*2) return Check(n, m-area, y+n, x, 0);
    else if(area*2 < m && m <= area*3) return Check(n, m-area*2, y+n, x+n, 0);
    else return Check(n, m-area*3, y+n-1, x+2*n-1, 3);
  }
  else if(dir == 1)
  {
    if(1 <= m && m <= area) return Check(n, m, y, x, 0);
    else if(area < m && m <= area*2) return Check(n, m-area, y, x+n, 1);
    else if(area*2 < m && m <= area*3) return Check(n, m-area*2, y+n, x+n, 1);
    else return Check(n, m-area*3, y+2*n-1, x+n-1, 2);
  }
  else if(dir == 2)
  {
    if(1 <= m && m <= area) return Check(n, m, y, x, 3);
    else if(area < m && m <= area*2) return Check(n, m-area, y-n, x, 2);
    else if(area*2 < m && m <= area*3) return Check(n, m-area*2, y-n, x-n, 2);
    else return Check(n, m-area*3, y-n+1, x-2*n+1, 1);
  }
  else
  {
    if(1 <= m && m <= area) return Check(n, m, y, x, 2);
    else if(area < m && m <= area*2) return Check(n, m-area, y, x-n, 3);
    else if(area*2 < m && m <= area*3) return Check(n, m-area*2, y-n, x-n, 3);
    else return Check(n, m-area*3, y-2*n+1, x-n+1, 0);
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  std::pair<int, int> ret = Check(N, M, 1, 1, 0);
  std::cout << ret.first << ' ' << ret.second;
  return 0;
}