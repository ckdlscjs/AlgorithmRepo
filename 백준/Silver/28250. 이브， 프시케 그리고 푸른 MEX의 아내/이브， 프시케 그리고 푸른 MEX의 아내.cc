#include <bits/stdc++.h>
long long int N, val, cnt[3];
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        std::cin >> val;
        if(val == 0) cnt[0]++;
        else if(val == 1) cnt[1]++;
        else cnt[2]++;
    }
    std::cout << (cnt[0] * (cnt[0]-1) / 2) + cnt[0]*cnt[2] + (cnt[0] * cnt[1] * 2);
    return 0;
}