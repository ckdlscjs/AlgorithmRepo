#include <bits/stdc++.h>
using namespace std;
long long int N, M, arr[1'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < N; i++) std::cin >> arr[i];
  for(int i = 0; i < M; i++)
  {
    std::sort(arr, arr+N);
    long long int sum = arr[0] + arr[1];
    arr[0] = sum;
    arr[1] = sum;
  }
  long long int sum = 0;
  for(int i = 0; i < N; i++) sum += arr[i];
  std::cout << sum;
  return 0;
}