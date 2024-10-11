#include <bits/stdc++.h>
using namespace std;
int N, m, n, A[2'005], totalA, B[2'005], totalB, Sums[1'000'005], ret;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  std::cin >> N >> m >> n;
  for(int i = 1; i <= m; i++)
  {
    std::cin >> A[i];
    A[i+m] = A[i];
    totalA += A[i];
  }
  for(int i = 1; i <= n; i++)
  {
    std::cin >> B[i];
    B[i+n] = B[i];
    totalB += B[i];
  }
  Sums[0]++;
  Sums[totalA]++;
  for(int i = 1; i <= m; i++)
  {
    int sum = 0;
    for(int j = 1; j < m; j++)
    {
      sum += A[i+j];
      Sums[sum]++;
    }
  }
  ret += Sums[N];
  for(int i = 1; i <= n; i++)
  {
    int sum = 0;
    for(int j = 1; j < n; j++)
    {
      sum += B[i+j];
      if(N >= sum) ret += Sums[N-sum];
    }
  }
  if(N >= totalB) ret += Sums[N-totalB];
  std::cout << ret;
  return 0;
}