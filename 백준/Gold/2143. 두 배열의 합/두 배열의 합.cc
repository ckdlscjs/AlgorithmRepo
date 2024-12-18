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

  for(int i = 0; i < psumsA.size(); i++)
  {
    int ub = std::upper_bound(psumsB.begin(), psumsB.end(), T - psumsA[i]) - psumsB.begin();
    int lb = std::lower_bound(psumsB.begin(), psumsB.end(), T - psumsA[i]) - psumsB.begin();
    res += ub - lb;
  }

  std::cout << res;
  return 0;
}