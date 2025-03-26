#include <bits/stdc++.h>
int N, arr[1'000'005], buttons[1'000'005], res;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::cin >> arr[n];
        if(arr[n] == buttons[n]) continue;
        res++;
        for(int i = 0; i < 3 && i < N; i++) buttons[n+i] = !buttons[n+i];
    }
    std::cout << res;
    return 0;
}