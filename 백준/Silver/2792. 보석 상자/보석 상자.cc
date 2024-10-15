#include <bits/stdc++.h>
using namespace std;
long long int N, M;
long long int arr[300'005];
bool Check(int mid)
{
  long long int cnt = 0;
  for(int i = 0; i < M; i++)
    cnt += (arr[i] / mid) + (arr[i] % mid ? 1 : 0);
  return cnt <= N;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;

  for(int i = 0; i < M; i++)
    std::cin >> arr[i];
  long long int lo = 0, hi = 1'000'000'005;
  while(lo+1 < hi)
  {
    //std::cout << lo << " : " << hi << '\n';
    long long int mid = (lo+hi) / 2;
    if(Check(mid)) hi = mid;
    else lo = mid;
  }
  std::cout << hi;
  return 0;
}
