#include <bits/stdc++.h>
using namespace std;
const int MaxN = 105;
int n, l;
int arr1[MaxN][MaxN];
int arr2[MaxN][MaxN];
int Check(int arr[][MaxN])
{
  int ret = 0;
  for(int i = 0; i < n; i++)
  {
    int cnt = 1;
    int j = 0;
    for(j = 0; j < n-1; j++)
    {
      if(arr[i][j] == arr[i][j+1]) cnt++;
      else if(arr[i][j] + 1 == arr[i][j+1] && cnt >= l) cnt = 1;
      else if(arr[i][j] - 1 == arr[i][j+1] && cnt >= 0) cnt = -l + 1;
      else break;
    }
    if(j >= n-1 && cnt >= 0) ret++;
  }
  return ret;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> l;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      std::cin >> arr1[i][j];
      arr2[j][i] = arr1[i][j];
    }
  }
  std::cout << Check(arr1) + Check(arr2);
  return 0;
}