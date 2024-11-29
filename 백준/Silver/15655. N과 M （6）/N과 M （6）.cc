#include <bits/stdc++.h>
using namespace std;
int N, M, arr[10];
void Check(int idx, int cnt, int* res)
{
  if(cnt >= M)
  {
    for(int i = 0; i < cnt; i++)
      std::cout << *(res+i) << ' ';
    std::cout << '\n';
    return;
  }
  for(int i = idx; i < N; i++)
  {
    res[cnt] = arr[i];
    Check(i+1, cnt+1, res);
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < N; i++)
    std::cin >> arr[i];
  std::sort(arr, arr+N, std::less<>());
  int res[10];
  Check(0, 0, res);
  return 0;
}