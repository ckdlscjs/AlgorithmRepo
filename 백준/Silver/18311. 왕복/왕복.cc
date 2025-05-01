#include <bits/stdc++.h>
using namespace std;
long long N, K, arr[200'005];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> K;
    for(int n = 1; n <= N; n++)
    {
        std::cin >> arr[n];
        arr[n] += arr[n-1];
    }
    for(int n = 1; n <= N; n++)
    {
        arr[n+N] = arr[N-(n-1)] - arr[N-n];
        arr[n+N] += arr[n+N-1];
    }
    for(int n = 1; n <= N*2; n++)
    {
        if(K <= arr[n]-1)
        {
            std::cout << (n <= N ? n : 2*N - n + 1);
            return 0;
        }
    }
    return 0;
}
