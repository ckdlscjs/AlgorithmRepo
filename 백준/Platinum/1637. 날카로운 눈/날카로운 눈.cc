#include <bits/stdc++.h>
long long int N, A[20'005], B[20'005], C[20'005], sum;
long long int Check(long long int mid)
{
  int ret = 0;
  for(int i = 0; i < N; i++)
    ret += (mid >= A[i] ? ((std::min(mid, C[i]) - A[i]) / B[i]) + 1 : 0);
  return ret;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> A[i] >> C[i] >> B[i];
    sum += ((C[i] - A[i]) / B[i]) + 1;
  }
  if(sum % 2 == 0)
  {
    std::cout << "NOTHING";
    return 0;
  }
  long long int lo = -1, hi = 2'147'483'648;
  while(lo + 1 < hi)
  {
    long long int mid = (lo + hi) / 2;
    if(Check(mid) % 2) hi = mid;
    else lo = mid;
  }
  std::cout << hi << ' ' << Check(hi) - Check(hi-1);
  return 0;
}