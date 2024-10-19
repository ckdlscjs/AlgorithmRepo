#include <bits/stdc++.h>
using namespace std;
long long int arr[10'005];
long long int N, M;
bool Check(long long int mid)
{
  long long int cnt = M;
  for(int i = 0; i < M; i++)
    cnt += mid / arr[i];
  return N <= cnt;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < M; i++)
    std::cin >> arr[i];
  if(N <= M)
  {
    std::cout << N;
    return 0;
  }
  long long int lo = 0, hi = 60'000'000'005;
  while(lo + 1 < hi)
  {
    long long int mid = (lo + hi) / 2;
    if(Check(mid)) hi = mid;
    else lo = mid;
  }
  long long int sum = M;
  for(int i = 0; i < M; i++) sum += lo/arr[i];
  for(int i = 0; i < M; i++)
  {
    if(hi % arr[i] == 0) sum++;
    if(sum == N)
    {
      std::cout << i+1;
      return 0;
    }
  }
  return 0;
}