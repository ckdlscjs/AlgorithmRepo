#include <bits/stdc++.h>
int N, K, Y, S;
int arr[8][2];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> N >> K;
  for(int i = 0; i < N; i++)
  {
    std::cin >> S >> Y;
    arr[Y][S]++;
  }
  int ans = 0;
  for(int y = 1; y <= 6; y++)
  {
    for(int s = 0; s < 2; s++)
    {
      ans += (int)(std::ceil((double)arr[y][s] / K));
    }
  }
  std::cout << ans;
  return 0;
}