#include <bits/stdc++.h>
using namespace std;
long long int N, M;
const long long int Mod = 1'000'000'007;
std::vector<std::vector<long long int>> Multiply(const std::vector<std::vector<long long int>>& mat1, const std::vector<std::vector<long long int>>& mat2)
{
  std::vector<std::vector<long long int>> ret = {{0, 0}, {0, 0}};
  for(int i = 0; i < 2; i++)
  {
    for(int j = 0; j < 2; j++)
    {
      for(int idx = 0; idx < 2; idx++)
      {
        ret[i][j] += (mat1[i][idx] * mat2[idx][j]) % Mod;
      }
      ret[i][j] %= Mod;
    }
  }
  return ret;
}
std::vector<std::vector<long long int>> Fibo(long long int k)
{
  if(k <= 0) return {{1, 0}, {0, 1}};
  if(k <= 1) return {{1, 1}, {1, 0}};
  std::vector<std::vector<long long int>> temp = Fibo(k/2);
  temp = Multiply(temp, temp);
  if(k%2) temp = Multiply(temp, {{1, 1}, {1, 0}});
  return temp;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  long long int large = std::max(N, M);
  long long int small = std::min(N, M);
  while(large % small)
  {
    long long int temp = large % small;
    large = small;
    small = temp;
  }
  std::vector<std::vector<long long int>> ret = Fibo(small-1);
  std::cout << ret[0][0];
  return 0;
}