#include <bits/stdc++.h>
int N;
int arr[20];
bool CheckQueen(int y)
{
  for(int i = 0; i < y; i++)
    if(arr[y] == arr[i] || y-i == std::abs(arr[y] - arr[i]))
      return false;
  return true;
}
int Check(int y)
{
  if(y >= N)
    return 1;
  int ret = 0;
  for(int j = 0; j < N; j++)
  {
    arr[y] = j;
    if(CheckQueen(y))
      ret += Check(y+1);
  }
  return ret;
}
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  std::cout << Check(0);
  return 0;
}