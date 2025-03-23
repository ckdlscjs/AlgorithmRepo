#include <bits/stdc++.h>
int N, val;
std::priority_queue<int, std::vector<int>, std::less<int>> pq;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::cin >> val;
        if(val == 0)
        {
            if(pq.size())
            {
                std::cout << pq.top()<< '\n'; pq.pop();
            }
            else
                std::cout << 0 << '\n';
        }
        else
            pq.push(val);
    }
	return 0;
}