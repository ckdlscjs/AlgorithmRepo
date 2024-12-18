#include <bits/stdc++.h>
int T, N, M, A[1'005], B[1'005];
long long int res = 0;
std::vector<int> psumsA, psumsB;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  std::cin >> N;
  for(int i = 1; i <= N; i++)
  {
    std::cin >> A[i];
    psumsA.push_back(A[i]);
    A[i] += A[i-1];
  }
  for(int len = N; len >= 2; len--)
    for(int i = N; i - len >= 0; i--)
      psumsA.push_back(A[i] - A[i-len]);
  
  std::cin >> M;
  for(int i = 1; i <= M; i++)
  {
    std::cin >> B[i];
    psumsB.push_back(B[i]);
    B[i] += B[i-1];
  }
  for(int len = M; len >= 2; len--)
    for(int i = M; i - len >= 0; i--)
      psumsB.push_back(B[i] - B[i-len]);
      
  std::sort(psumsA.begin(), psumsA.end());
  std::sort(psumsB.begin(), psumsB.end());
  int lo, hi, ub, lb;
  for(int i = 0; i < psumsA.size(); i++)
  {
    lo = -1, hi = psumsB.size();
    while(lo + 1 < hi)
    {
      int mid = (lo + hi) / 2;
      if(psumsB[mid] + psumsA[i] > T) hi = mid;
      else lo = mid;
    }
    ub = hi;
    lo = -1, hi = psumsB.size();
    while(lo + 1 < hi)
    {
      int mid = (lo + hi) / 2;
      if(psumsB[mid] + psumsA[i] >= T) hi = mid;
      else lo = mid;
    }
    lb = hi;
    res += ub - lb;
  }

  std::cout << res;
  return 0;
}