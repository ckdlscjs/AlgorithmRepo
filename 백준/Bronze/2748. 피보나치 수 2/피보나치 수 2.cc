#include <bits/stdc++.h>
using namespace std;
long long int N;
std::vector<std::vector<long long int>> arr = {{1, 1}, {1, 0}};
std::vector<std::vector<long long int>> Multiply(const std::vector<std::vector<long long int>>& mat1, const std::vector<std::vector<long long int>>& mat2) 
{
  std::vector<std::vector<long long int>> temp(2, std::vector<long long int>(2, 0));
  for(int i = 0; i < 2; i++)
  {
    for(int j = 0; j < 2; j++)
    {
      for(int idx = 0; idx < 2; idx++)
      {
        temp[i][j] += mat1[i][idx] * mat2[idx][j];
      }
    }
  }
  return temp;
}
std::vector<std::vector<long long int>> Fibo(const std::vector<std::vector<long long int>>& mat, long long int k)
{
  if(k == 0) return {{1, 0}, {0, 1}};
  if(k == 1) return mat;
  std::vector<std::vector<long long int>> temp = Fibo(mat, k/2);
  std::vector<std::vector<long long int>> ans = Multiply(temp, temp);
  if(k % 2) ans = Multiply(ans, mat);
  return ans;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  std::vector<std::vector<long long int>> ans = Fibo(arr, N);
  std::cout << ans[1][0];
  return 0;
}