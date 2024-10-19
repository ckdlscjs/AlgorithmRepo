#include <bits/stdc++.h>
using namespace std;
int N, len, lis[105];
std::pair<int, int> arr[105];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
    std::cin >> arr[i].first >> arr[i].second;
  std::sort(arr, arr+N, std::less<>());
  for(int i = 0; i < N; i++)
  {
    if(i == 0 || lis[len-1] < arr[i].second)
    {
      lis[len++] = arr[i].second;
    }
    else
    {
      int lo = -1, hi = len;
      while(lo + 1 < hi)
      {
        int mid = (lo + hi) / 2;
        if(arr[i].second <= lis[mid]) hi = mid;
        else lo = mid;
      }
      lis[hi] = arr[i].second;
    }
  }
  std::cout << N - len;
  return 0;
}