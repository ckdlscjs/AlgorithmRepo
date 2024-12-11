#include <bits/stdc++.h>
using namespace std;
int N, arr[55], sum;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++) std::cin >> arr[i];
  std::sort(arr, arr+N);
  int left = 0, right = N-1;
  while(left <= right)
  {
    if(right-1 >= left && arr[right] >= 2 && arr[right-1] >= 2)
    {
      sum += arr[right] * arr[right-1];
      right-=2;
    }
    else if(left+1 <= right && arr[left] * arr[left+1] > arr[left] + arr[left+1])
    {
      sum += arr[left] * arr[left+1];
      left += 2;
    }
    else
      sum += arr[left++];
  }
  std::cout << sum;
  return 0;
}