#include <bits/stdc++.h>
using namespace std;
int N, S, arr[100'005], minLength = 100'005, sum;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> S;
    for(int n = 0; n < N; n++) std::cin >> arr[n];
    int l = 0, r = 0;
    while(l <= r && r < N)
    {
        sum += arr[r];
        if(sum < S)
        {
            r++;
        }
        else
        {
            minLength = std::min(minLength, r - l + 1);
            sum -= arr[l++];
            sum -= arr[r];
        }
    }
    std::cout << (minLength >= 100'000 ? 0 : minLength);
    return 0;
}
