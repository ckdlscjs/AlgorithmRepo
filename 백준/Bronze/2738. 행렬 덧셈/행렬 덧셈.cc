#include <bits/stdc++.h>
using namespace std;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n, m;
  std::cin >> n >> m;
  int* arr[n];
  for(int i = 0; i < n; i++)
  {
    arr[i] = new int[m];
    for(int j = 0; j < m; j++)
    {
      int input;
      std::cin >> input;
      arr[i][j] = input;
    }
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      int input;
      std::cin >>input;
      arr[i][j] += input;
      std::cout << arr[i][j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}