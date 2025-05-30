/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, arr[22][22], psums[22], sums, ans = (100+100)*22;
void Check(int cur, int idx, int sum)
{
    if(cur >= N / 2)
    {
        ans = std::min(ans, std::abs(sum));
        return;
    }
    if(idx >= N) return;
    Check(cur+1, idx+1, sum - psums[idx]);
    Check(cur, idx+1, sum);
}
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin >> arr[i][j];
            psums[i] += arr[i][j];
            psums[j] += arr[i][j];
            sums += arr[i][j];
        }
    }
    Check(0, 0, sums);
    std::cout << ans;
    return 0;
}
