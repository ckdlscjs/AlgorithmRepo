#include <bits/stdc++.h>
using namespace std;
long long int N, B;
std::vector<std::vector<int>> arr;
std::vector<std::vector<int>> Multiply(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2) 
{
  std::vector<std::vector<int>> temp(N, std::vector<int>(N, 0));
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      for(int idx = 0; idx < N; idx++)
      {
        temp[i][j] += (mat1[i][idx] * mat2[idx][j])%1000;
      }
      temp[i][j] %= 1000;
    }
  }
  return temp;
}
std::vector<std::vector<int>> Square(const std::vector<std::vector<int>>& mat, long long int k)
{
  if(k <= 1) return mat;
  std::vector<std::vector<int>> temp = Square(mat, k/2);
  std::vector<std::vector<int>> ans = Multiply(temp, temp);
  if(k % 2) ans = Multiply(ans, mat);
  return ans;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> B;
  arr.resize(N, std::vector<int>(N));
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      std::cin >> arr[i][j];
  std::vector<std::vector<int>> ans = Square(arr, B);
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      std::cout << ans[i][j] % 1000 << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}