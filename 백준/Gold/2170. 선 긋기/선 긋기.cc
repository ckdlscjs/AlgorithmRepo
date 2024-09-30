#include <bits/stdc++.h>
const int MaxN = 1'000'005;
long long int n, l, r, sum;
std::pair<long long int, long long int> arr[MaxN]; 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for(int i = 0; i < n; i++)
        std::cin >> arr[i].first >> arr[i].second;
    std::sort(arr, arr+n, std::less<>());
    l = arr[0].first;
    r = arr[0].second;
    for(int i = 1; i < n; i++)
    {
        if(arr[i].first > r)
        {
            sum += r-l;
            l = arr[i].first;
            r = arr[i].second;
            continue;
        }
        if(arr[i].second > r)
            r = arr[i].second;
    }
    sum += r-l;
    std::cout << sum;
    return 0;
}