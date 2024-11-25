#include <bits/stdc++.h>
using namespace std;
long long int N, S, val, arr[25];
long long int Check(int idx, int mask, long long int sum)
{
  long long ret = 0;
  if(idx >= N)
    return (sum == S && mask) ? 1 : 0;
  ret += Check(idx+1, mask, sum);
  ret += Check(idx+1, mask | (1 << idx), sum + arr[idx]);
  return ret;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> S;
  for(int i = 0; i < N; i++)
    std::cin >> arr[i];
  std::cout << Check(0, 0, 0);
  return 0;
}