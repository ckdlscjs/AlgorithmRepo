#include <bits/stdc++.h>
int N, M, i, j, psum[100'005];
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int idx = 1; idx <= N; idx++)
  {
    std::cin >> psum[idx];
    psum[idx] += psum[idx-1];
  }
  for(int m = 0; m < M; m++)
  {
    std::cin >> i >> j;
    std::cout << psum[j] - psum[i-1] << '\n';
  }
  
  return 0;
}