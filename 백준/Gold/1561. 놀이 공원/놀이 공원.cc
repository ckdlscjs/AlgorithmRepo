#include <bits/stdc++.h>
long long int N, M, arr[10'005], cnt;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < M; i++) std::cin >> arr[i];
  if(N <= M)
  {
    std::cout << N;
    return 0;
  }
  long long int lo = -1, hi = 60'000'000'005;
  while(lo + 1 < hi)
  {
    long long int mid = (lo + hi) / 2;
    if([&](){
      cnt = M;
      for(int i = 0; i < M; i++)
        cnt += mid / arr[i];
      return cnt < N;
    }()) lo = mid;
    else hi = mid;
  }
  cnt = M;
  for(int i = 0; i < M; i++) cnt += lo / arr[i];
  for(int i = 0; i < M; i++)
  {
    if(hi % arr[i] == 0) cnt++;
    if(cnt == N)
    {
      std::cout << i + 1;
      return 0;
    }
  }
  return 0;
}