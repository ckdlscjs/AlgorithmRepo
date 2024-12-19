#include <bits/stdc++.h>
using namespace std;
int n, e;
int arr[100'005];
bool chk[100'005];
long long int sum;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for(int i = 0; i < n; i++)
      std::cin >> arr[i];
    for(int s = 0; s < n; s++)
    {
      while(e < n && !chk[arr[e]])
        chk[arr[e++]] = true;
      sum += e-s;
      chk[arr[s]] = false;
    }
    std::cout << sum;
    return 0;
}