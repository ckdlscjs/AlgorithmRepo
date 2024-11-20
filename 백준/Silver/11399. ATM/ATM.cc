#include <bits/stdc++.h>
using namespace std;
int N, arr[1005], psum[1005], sum;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 1; i <= N; i++) std::cin >> arr[i];
  std::sort(arr + 1, arr+N+1, std::less<int>());
  for(int i = 0; i <= N; i++)
  {
    psum[i] += psum[i-1] + arr[i];
    sum += psum[i];
  }
  std::cout << sum;
  return 0;
}