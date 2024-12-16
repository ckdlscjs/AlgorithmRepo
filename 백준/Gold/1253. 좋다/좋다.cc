#include <bits/stdc++.h>
int N, arr[2'005], cnt;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++) std::cin >> arr[i];
  std::sort(arr, arr+N);
  for(int i = 0; i < N; i++)
  {
    int left = 0, right = N-1;
    while(left < right)
    {
      if(arr[left] + arr[right] > arr[i]) right--;
      else if(arr[left] + arr[right] < arr[i]) left++;
      else if(left == i) left++;
      else if(right == i) right--;
      else if(arr[left] + arr[right] == arr[i])
      {
        cnt++;
        break;
      }
    }
  }
  std::cout << cnt;
  return 0;
}