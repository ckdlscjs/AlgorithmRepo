/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, arr[1500*1500+2];
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int i = 0; i < N*N; i++) std::cin >> arr[i];
    std::sort(arr, arr+N*N);
    std::cout << arr[N*N-N];
    return 0;
}
