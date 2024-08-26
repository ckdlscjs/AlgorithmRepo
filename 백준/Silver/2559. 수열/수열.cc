#include <bits/stdc++.h>
using namespace std;
int N, K;
int sums[100005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> K;
  for(int i = 1; i <= N; i++)
  {
    std::cin >> sums[i];
    sums[i] += sums[i-1];
    //std::cout << sums[i] << ' ';
  }
  int result = -123456789;
  for(int i = K; i <= N; i++)
    result = std::max(sums[i] - sums[i-K], result);
  std::cout << result;
  return 0;
}