/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, P[1'005], res;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int n = 1; n <= N; n++) std::cin >> P[n];
    std::sort(P+1, P+N+1);
    for(int n = 1; n <= N; n++)
    {
        P[n] += P[n-1];
        res += P[n];
    }
    std::cout << res;
    return 0;
}
