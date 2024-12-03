#include <bits/stdc++.h>
using namespace std;
int N, M, arr[1030][1030], ly, lx, ry, rx;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 1; i <= N; i++)
  {
    for(int j = 1; j <= N; j++)
    {
      std::cin >> arr[i][j];
      arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
    }
  }
  for(int i = 0; i < M; i++)
  {
    std::cin >> ly >> lx >> ry >> rx;
    std::cout << arr[ry][rx] - arr[ry][lx-1] - arr[ly-1][rx] + arr[ly-1][lx-1] << '\n';
  }
  return 0;
}