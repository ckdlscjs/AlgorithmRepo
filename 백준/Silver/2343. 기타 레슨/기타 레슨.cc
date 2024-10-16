#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[100'005];
bool Check(int val)
{
  int cnt = 0;
  int sum = 0;
  for(int i = 0; i < N; i++)
  {
    sum += arr[i];
    if(sum > val)
    {
      if(arr[i] > val)
        return false;
      cnt++;
      sum = arr[i];
    }
  }
  return cnt < M;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < N; i++)
    std::cin >> arr[i];
  int lo = 0, hi = 1'000'000'005;
  while(lo + 1 < hi)
  {
    int mid = (lo + hi) / 2;
    if(Check(mid)) hi = mid;
    else lo = mid;
  }
  std::cout << hi;
  return 0;
}