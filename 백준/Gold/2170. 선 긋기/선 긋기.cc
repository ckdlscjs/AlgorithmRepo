#include <bits/stdc++.h>
const int MaxN = 1'000'005;
long long int n, l, sum;
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
    for(int i = 0; i < n; i++)
    {
        if(arr[i].second < l)
            continue;
        if(arr[i].first > l)
            l = arr[i].first;
        sum += arr[i].second - l;
        l = arr[i].second;
    }
    std::cout << sum;
    return 0;
}