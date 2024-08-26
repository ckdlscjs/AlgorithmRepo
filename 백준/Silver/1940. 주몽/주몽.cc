#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[15005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < N; i++)
    std::cin >> arr[i];
  std::sort(arr, arr+N, std::less<>());
  int left = 0, right = N-1;
  int cnt = 0;
  while(left < right)
  {
    int sum = arr[left] + arr[right];
    if(sum == M)
    {
      cnt++;
      left++;
      right--;
    }
    else if(sum < M)
      left++;
    else
      right--;
  }
  std::cout << cnt;
  return 0;
}