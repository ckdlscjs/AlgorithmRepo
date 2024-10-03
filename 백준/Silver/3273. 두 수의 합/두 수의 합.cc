#include <bits/stdc++.h>
using namespace std;
long long int n, x, s, e, sum;
int arr[100'005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for(int i = 0; i < n; i++)
      std::cin >> arr[i];
    std::sort(arr,arr+n, std::less<>());
    std::cin >> x;
    s = 0;
    e = n-1;
    while(s < e)
    {
      if(arr[s] + arr[e] == x)
        sum++;
      if(arr[s] + arr[e] > x)
        e--;
      else
        s++;
    }
    std::cout << sum;
    return 0;
}