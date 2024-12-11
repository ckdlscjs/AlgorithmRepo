#include <bits/stdc++.h>
using namespace std;
long long int T, N, res, high, arr[1'000'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  for(int t = 0; t < T; t++)
  {
    res = high = 0;
    std::cin >> N;
    for(int i = 0; i < N; i++)
      std::cin >> arr[i];
    for(int i = N-1; i >= 0; i--)
    {
      if(arr[i] >= high)
        high = arr[i];
      else
        res += high - arr[i];
    }
    std::cout << res << '\n';
  }
  return 0;
}