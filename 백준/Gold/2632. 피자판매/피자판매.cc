#include <bits/stdc++.h>
using namespace std;
int N, m, n, A[1005], ASums[2005], B[1005], BSums[2005], ret;
std::unordered_map<int, int> CntA, CntB;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  std::cin >> N >> m >> n;
  for(int i = 1; i <= m; i++)
  {
    std::cin >> A[i];
    ASums[i] = ASums[i-1] + A[i];
  }
  for(int i = m+1; i <= m*2; i++)
    ASums[i] = ASums[i-1] + A[i-m];
  for(int interval = 1; interval <= m; interval++)
  {
    for(int start = interval; start < m + interval; start++) //돌아서 시작지점 이전까지
    {
      int sum = ASums[start] - ASums[start - interval];
      CntA[sum]++;
      if(interval == m) break;
    }
  }
  
  for(int i = 1; i <= n; i++)
  {
    std::cin >> B[i];
    BSums[i] = BSums[i-1] + B[i];
  }
  for(int i = n+1; i <= n*2; i++)
    BSums[i] = BSums[i-1] + B[i-n];
  for(int interval = 1; interval <= n; interval++)
  {
    for(int start = interval; start < n + interval; start++)
    {
      int sum = BSums[start] - BSums[start - interval];
      CntB[sum]++;
      if(interval == n) break;
    }
  }
  
  for(int i = 1; i < N; i++)
    ret += CntA[i] * CntB[N-i];
  ret += CntA[N] + CntB[N];
  std::cout << ret;
  return 0;
}