/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
long long T;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    for(long long t = 0; t < T; t++)
    {
        long long N, res = 0;
        std::cin >> N;
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
        for(long long n = 0; n < N; n++)
        {
            long long val;
            std::cin >> val;
            pq.push(val);
        }
        while(pq.size() >= 2)
        {
            long long val1 = pq.top();pq.pop();
            long long val2 = pq.top();pq.pop();
            res += (val1 + val2);
            pq.push(val1 + val2);
        }
        std::cout << res << '\n';
    }
    return 0;
}
