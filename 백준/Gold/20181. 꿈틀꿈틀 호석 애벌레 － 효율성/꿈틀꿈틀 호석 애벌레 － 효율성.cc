#include <bits/stdc++.h>
long long int N, K, psum[100'005], dp[100'005], l, r;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> K;
  for(int i = 1; i <= N; i++)
  {
    std::cin >> psum[i];
    psum[i] += psum[i-1];
  }
  l = 0, r = 1;
  while(r <= N)
  {
    long long int sum = psum[r] - psum[l];
    
    //std::cout << r << ", "<<l <<":" << dp[r] << '\n';
    if(sum < K)
    {
      dp[r] = std::max(dp[r], dp[r-1]);
      r++;
    }
    else
    {
      dp[r] = std::max(dp[r], dp[l] + std::max(sum - K, (long long int)0));
      l++;
    }
  }
  std::cout << dp[N];
  return 0;
}