#include <bits/stdc++.h>
using namespace std;
int N, arr[100'005], res;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
    std::cin >> arr[i];
  std::sort(arr, arr+N);
  for(int i = 0; i < N; i++)
    res = std::max((N-i) * arr[i], res);
  std::cout << res;
  return 0;
}