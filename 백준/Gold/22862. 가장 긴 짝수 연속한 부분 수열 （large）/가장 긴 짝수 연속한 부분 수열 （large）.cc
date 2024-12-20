#include <bits/stdc++.h>
using namespace std;
int N, K, arr[1'000'005], e, k, len;
bool chk[1'000'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> K;
  for(int i = 0; i < N; i++) std::cin >> arr[i];
  for(int s = 0; s < N; s++)
  {
    while(e < N)
    {
      if(arr[e] % 2)
      {
        if(k >= K)
          break;
        chk[e] = true;
        k++;
      }
      e++;
    }
    len = std::max(len, e-s-k);
    chk[s] = false;
    if(arr[s] % 2)
      k--;
  }
  std::cout << len;
  return 0;
}