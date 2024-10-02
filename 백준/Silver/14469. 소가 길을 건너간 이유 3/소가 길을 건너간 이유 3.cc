#include <bits/stdc++.h>
int n, sum;
std::pair<int, int> arr[105];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for(int i = 0; i < n; i++)
      std::cin >> arr[i].first >> arr[i].second;
    std::sort(arr, arr+n, std::less<>());
    int r = arr[0].first + arr[0].second;
    for(int i = 1; i < n; i++)
    {
      if(arr[i].first <= r)
        r += arr[i].second;
      else
        r = arr[i].first + arr[i].second;
    }
    std::cout << r;
    return 0;
}