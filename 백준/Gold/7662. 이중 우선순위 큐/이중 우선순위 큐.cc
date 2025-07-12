/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int T, K;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
    for(T; T > 0; T--)
    {
        std::cin >> K;
        int size = 0;
        std::unordered_map<int, int> cnts_low;
        std::unordered_map<int, int> cnts_high;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq_low;
        std::priority_queue<int, std::vector<int>, std::less<int>> pq_high;
        for(K; K > 0; K--)
        {
            char ch;
            int n;
            std::cin >> ch >> n;
            if(ch == 'D')
            {
                if(size <= 0) continue;
                size--;
                if(n == 1)
                {
                    while(pq_high.size() && cnts_high[pq_high.top()])
                    {
                       cnts_high[pq_high.top()]--;
                       pq_high.pop();
                    }
                    cnts_low[pq_high.top()]++;
                    pq_high.pop();
                }
                else
                {
                    while(pq_low.size() && cnts_low[pq_low.top()])
                    {
                       cnts_low[pq_low.top()]--;
                       pq_low.pop();
                    }
                    cnts_high[pq_low.top()]++;
                    pq_low.pop();
                }
            }
            else
            {
                pq_low.push(n);
                pq_high.push(n);
                size++;
            }
        }
        while(pq_low.size() && cnts_low[pq_low.top()])
        {
            cnts_low[pq_low.top()]--;
            pq_low.pop();
        }
        while(pq_high.size() && cnts_high[pq_high.top()])
        {
            cnts_high[pq_high.top()]--;
            pq_high.pop();
        }
        if(size <= 0)
        {
            std::cout << "EMPTY" << '\n';
        }
        else
        {
            std::cout << pq_high.top() << ' ' << pq_low.top() << '\n';
        }
    }
	return 0;
}

