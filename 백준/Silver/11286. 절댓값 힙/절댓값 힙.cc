/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N;
struct comp
{
    bool operator()(const int& a, const int& b)
    {
        return std::abs(a) == std::abs(b) ? a > b : std::abs(a) > std::abs(b);
    }
};
std::priority_queue<int, std::vector<int>, comp> pq;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        int val;
        std::cin >> val;
        if(!val)
        {
            if(pq.empty())
            {
                std::cout << 0 << '\n';
            }
            else
            {
                std::cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(val);
        }
    }
    return 0;
}
