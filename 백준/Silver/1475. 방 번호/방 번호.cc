#include <bits/stdc++.h>
int arr[10];
int N;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> N;
  int maxVal = 0;
  while(N)
  {
    arr[N % 10]++;
    if(N % 10 == 6 || N % 10 == 9)
      maxVal = std::max(maxVal, (int)std::ceil((double)(arr[6] + arr[9])/2));
    else
      maxVal = std::max(maxVal, arr[N % 10]);
    N /= 10;
  }
  std::cout << maxVal;
  return 0;
}