#include <bits/stdc++.h>
using namespace std;
long long int N, arr[4'005][4], lo, hi, ub, lb, cnt;
std::vector<long long int> A, B;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < 4; j++)
      std::cin >> arr[i][j];
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      A.push_back(arr[i][0] + arr[j][1]);
  std::sort(A.begin(), A.end());
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      B.push_back(arr[i][2] + arr[j][3]);
  std::sort(B.begin(), B.end());
  for(int i = 0; i < A.size(); i++)
  {
    lo = -1, hi = B.size();
    while(lo + 1 < hi)
    {
      int mid = (lo + hi) / 2;
      if(A[i] + B[mid] > 0) hi = mid;
      else lo = mid;
    }
    ub = hi;
    lo = -1, hi = B.size();
    while(lo + 1 < hi)
    {
      int mid = (lo + hi) / 2;
      if(A[i] + B[mid] >= 0) hi = mid;
      else lo = mid;
    }
    lb = hi;
    cnt += ub - lb;
  }
  std::cout << cnt;
  return 0;
}