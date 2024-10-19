#include <bits/stdc++.h>
using namespace std;
long long int arr[1'000'005];
int S, C, L;
bool Check(long long int mid)
{
  long long int cnt = 0;
  for(int i = 0; i < S; i++)
    cnt += arr[i] / mid;
  return C <= cnt;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> S >> C;
  long long int sum = 0;
  for(int i = 0; i < S; i++)
  {
    std::cin >> arr[i];
    sum += arr[i];
  }
    
  long long int lo = 0, hi = 1'000'000'005;
  while(lo + 1 < hi)
  {
    long long int mid = (lo + hi) / 2;
    if(Check(mid)) lo = mid;
    else hi = mid;
  }
  sum -= lo * C;
  std::cout << sum;
  return 0;
}