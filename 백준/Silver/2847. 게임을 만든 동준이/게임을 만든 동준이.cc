#include <bits/stdc++.h>
using namespace std;
int N, arr[105], res;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++) std::cin >> arr[i];
  int start = arr[N-1];
  for(int i = N-2; i >= 0; i--)
  {
    if(arr[i] >= start)
    {
      start--;
      res += arr[i] - start;
    }
    else
      start = arr[i];
  }
  std::cout << res;
  return 0;
}