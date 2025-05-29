/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, arr[1'000'005], sorted[1'000'005];
std::unordered_map<int, int> cnts;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::cin >> arr[n];
        sorted[n] = arr[n];
    }
    std::sort(sorted, sorted + N);
    int prv = sorted[0], cnt = 0;
    for(int n = 0; n < N; n++)
    {
        if(prv != sorted[n])
        {
            cnt++;
            prv = sorted[n];
        }
        cnts[sorted[n]] = cnt;
    }
    for(int n = 0; n < N; n++)
    {
        std::cout << cnts[arr[n]] << ' ';
    }
    
    return 0;
}
