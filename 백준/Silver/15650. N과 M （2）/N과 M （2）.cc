#include <bits/stdc++.h>
using namespace std;
int N, M, arr[15];
void Check(int idx, int cnt)
{
  if(cnt >= M)
  {
    for(int i = 0; i < M; i++)
      std::cout << arr[i] << ' ';
    std::cout << '\n';
    return;
  }
  for(int i = idx+1; i <= N; i++)
  {
    arr[cnt] = i;
    Check(i, cnt+1);
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  Check(0, 0);
  return 0;
}