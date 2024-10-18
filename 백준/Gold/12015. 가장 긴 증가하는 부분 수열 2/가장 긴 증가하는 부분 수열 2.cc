#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1'000'005;
int arr[MaxN];
int previdx[MaxN];
int lis[MaxN];
int N, lidx;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::fill(previdx, previdx+MaxN, -1);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> arr[i];
    if(i == 0 || lis[lidx-1] < arr[i])
    {
      previdx[lidx] = i;
      lis[lidx++] = arr[i];
    }
    else
    {
      int lo = -1, hi = lidx;
      while(lo + 1 < hi)
      {
        int mid = (lo + hi) / 2;
        if(lis[mid] >= arr[i]) hi = mid;
        else lo = mid;
      }
      previdx[hi] = i;
      lis[hi] = arr[i];
    }
  }
  //for(int i = 0; i < lidx; i++)
    //std::cout << previdx[i] << ' ';
  std::cout << lidx;
  return 0;
}