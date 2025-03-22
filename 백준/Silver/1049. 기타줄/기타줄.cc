#include <bits/stdc++.h>
int N, M, a, b, sum;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq1;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq6;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for(int m = 0; m < M; m++)
    {
        std::cin >> a >> b;
        pq1.push(b);
        pq6.push(a);
        pq6.push(b*6);
    }
    std::cout << ((N / 6) * pq6.top() + ((N % 6) * pq1.top() < pq6.top() ? (N % 6) * pq1.top() :  pq6.top()));
	return 0;
}