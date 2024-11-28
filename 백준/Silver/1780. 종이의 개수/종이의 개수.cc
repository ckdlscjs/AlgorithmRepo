#include <bits/stdc++.h>
using namespace std;
int N, arr[2200][2200], res[3];
int Check(int n, int y, int x)
{
  if(n <= 1)
    return arr[y][x];
  int cnts[9];
  cnts[0] = Check(n/3, y, x);
  cnts[1] = Check(n/3, y, x + n/3);
  cnts[2] = Check(n/3, y, x + n/3*2);
  cnts[3] = Check(n/3, y + n/3, x);
  cnts[4] = Check(n/3, y + n/3, x + n/3);
  cnts[5] = Check(n/3, y + n/3, x + n/3*2);
  cnts[6] = Check(n/3, y + n/3*2, x);
  cnts[7] = Check(n/3, y + n/3*2, x + n/3);
  cnts[8] = Check(n/3, y + n/3*2, x + n/3*2);
  int temp[3] = {0, 0, 0};
  for(int i = 0; i < 9; i++)
  {
    if(cnts[i] == -1)
      temp[0]++;
    else if(cnts[i] == 0)
      temp[1]++;
    else if(cnts[i] == 1)
      temp[2]++;
  }
  if(temp[0] == 9)
    return -1;
  else if(temp[1] == 9)
    return 0;
  else if(temp[2] == 9)
    return 1;
  res[0] += temp[0];
  res[1] += temp[1];
  res[2] += temp[2];
  return -10;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      std::cin >> arr[i][j];
  int ret = Check(N, 0, 0);
  if(ret == -1)
    res[0]++;
  else if(ret == 0)
    res[1]++;
  else if(ret == 1)
    res[2]++;
  std::cout << res[0] << '\n' << res[1] << '\n' << res[2];
  return 0;
}