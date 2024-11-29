#include <bits/stdc++.h>
using namespace std;
int N;
char arr[(3* 1 << 10)][(6*1<<10)];
void Check(int n, int y, int x)
{
  if(n <= 3)
  {
    arr[y][x] = '*';
    arr[y+1][x-1] = arr[y+1][x+1] =  '*';
    arr[y+2][x-2] = arr[y+2][x-1] = arr[y+2][x] = arr[y+2][x+1] = arr[y+2][x+2] = '*';
    return;
  }
  Check(n/2, y, x);
  Check(n/2, y+n/2, x-n/2);
  Check(n/2, y+n/2, x+n/2);
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  std::fill_n(&arr[0][0], (3* 1 << 10) * (6*1<<10), ' ');
  Check(N, 0, N-1);
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N*2 - 1; j++)
    {
      std::cout << arr[i][j];
    }
    std::cout << '\n';
  }
  return 0;
}