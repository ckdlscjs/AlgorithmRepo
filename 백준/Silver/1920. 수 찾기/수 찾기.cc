#include <bits/stdc++.h>
int N, M, arr[100'005], input;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++) std::cin >> arr[n];
    std::sort(arr, arr+N);
    std::cin >> M;
    for(int m = 0; m < M; m++)
    {
        std::cin >> input;
        int lo = -1, hi = N;
        while(lo + 1 < hi)
        {
            int mid = (lo + hi) / 2;
            if(arr[mid] >= input) hi = mid;
            else lo = mid;
        }
        if(hi >= N || arr[hi] != input)
            std::cout << 0 <<'\n';
        else
            std::cout << 1 << '\n';
    }
   
	return 0;
}