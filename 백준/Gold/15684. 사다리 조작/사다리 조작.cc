#include <bits/stdc++.h>
using namespace std;
const int MaxN = 35;
int arr[MaxN][MaxN];
int n, m, h;
int result = 4;
bool IsPossible(int y, int x)
{
  if(arr[y][x] || arr[y][x+1])
    return false;
  return true;
}
bool IsPass()
{
  for(int j = 1; j <= n; j++)
  {
    int cur = j;
    for(int i = 1; i <= h; i++)
    {
      if(!arr[i][cur])
        continue;
      cur = arr[i][cur];
    }
    if(cur != j)
      return false;
  }
  return true;
}
void Check(int iidx, int jidx, int cnt)
{
  if(iidx > h)
    return;
  if(cnt > 3)
    return;
  if(IsPass())
  {
    result = std::min(result, cnt);
    return;
  }
  else if(cnt + 1 < result)
  {
    int ni = iidx;
    int nj = jidx+1;
    if(nj > n)
    {
      ni++;
      nj = 1;
    }
    if(IsPossible(iidx, jidx))
    {
      arr[iidx][jidx] = jidx+1;
      arr[iidx][jidx+1] = jidx;
      Check(ni, nj, cnt+1);
      arr[iidx][jidx+1] = 0;
      arr[iidx][jidx] = 0;
    }
    Check(ni, nj, cnt);
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m >> h;
  for(int i = 0; i < m; i++)
  {
    int a, b;
    std::cin >> a >> b;
    arr[a][b] = b+1;
    arr[a][b+1] = b;
  }
  Check(1, 1, 0);
  std::cout << (result >= 4 ? -1 : result);
  return 0;
}