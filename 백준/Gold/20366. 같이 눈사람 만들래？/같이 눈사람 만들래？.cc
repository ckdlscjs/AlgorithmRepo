#include <bits/stdc++.h>
using namespace std;
long long int N, arr[605];
std::vector<long long int> sums;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++) std::cin >> arr[i];
  std::sort(arr, arr+N);
  long long int ans = 2'000'000'005;
  for(int i = 0; i < N-3; i++)
  {
    for(int j = i+3; j < N; j++)
    {
      int l = i+1, r = j-1;
      while(l < r)
      {
        long long int num1 = arr[i] + arr[j];
        long long int num2 = arr[l] + arr[r];
        long long int temp = num1 - num2;
        ans = std::min(ans, std::abs(temp));
        if(num1 > num2) l++;
        else if(num1 < num2) r--;
        else
        {
          std::cout << 0;
          return 0;
        }
      }
    }
  }
  std::cout << ans;
  return 0;
}