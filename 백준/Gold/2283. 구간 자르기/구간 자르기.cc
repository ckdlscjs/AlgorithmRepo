#include <bits/stdc++.h>
int N, K, mb, chk[1'000'005], psum[1'000'005], l, r, sum;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> K;
  for(int i = 0; i < N; i++)
  {
    std::cin >> l >> r;
    chk[l]++;
    chk[r]--;
    mb = std::max(mb, r);
  }
  for(int i = 0; i <= r; i++)
  {
    if(i == 0)
    {
      psum[0] = chk[i];
      continue;
    }
    psum[i] = psum[i-1] + chk[i];
  }
  l = r = 0;
  while(r < mb || l < mb)
  {
    if(sum < K)
      sum += psum[r++];
    else if(sum > K)
      sum -= psum[l++];
    else
    {
      std::cout << l << ' ' << r;
      return 0;
    }
  }
  std::cout << 0 << ' ' << 0;
  return 0;
}