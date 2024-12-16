#include <bits/stdc++.h>
int N, M, val;
bool arr[20'000'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> val;
    arr[val + 10'000'000] = true;
  }
  std::cin >> M;
  for(int i = 0; i < M; i++)
  {
    std::cin >> val;
    std::cout << arr[val + 10'000'000] << ' ';
  }
  return 0;
}