#include <bits/stdc++.h>
using namespace std;
int N, M, arr[15];
void Check(int idx)
{
  if(idx >= M)
  {
    for(int i = 0; i < M; i++)
      std::cout << arr[i] << ' ';
    std::cout << '\n';
    return;
  }
  for(int i = 0; i < N; i++)
  {
    arr[idx] = i+1;
    Check(idx+1);
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  Check(0);
  return 0;
}