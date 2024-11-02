#include <bits/stdc++.h>
long long int arr[10'005];
long long int K, N;
bool Check(long long int mid)
{
    long long int cnt = 0;
    for(int i = 0; i < K; i++)
    {
        cnt += arr[i] / mid;
    }
    return cnt >= N;
}
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> K >> N;
    for(int i = 0; i < K; i++)
      std::cin >> arr[i];
    long long int lo = 0, hi = 1e18;
    while(lo + 1 < hi)
    {
        long long int mid = (lo + hi) / 2;
        if(Check(mid)) lo = mid;
        else hi = mid;
    }
    std::cout << lo;
    return 0;
}