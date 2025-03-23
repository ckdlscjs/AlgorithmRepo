#include <bits/stdc++.h>
using pii = std::pair<int, int>;
std::vector<int> arr;
int N, val;
struct compare
{
    bool operator()(const pii& a, const pii& b)
    {
        return a.first == b.first ? arr[a.second] > arr[b.second] : a.first > b.first;
    }
};
std::priority_queue<pii, std::vector<pii>, compare> pq;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::cin >> val;
        if(val != 0)
        {
            arr.push_back(val);
            pq.push({std::abs(val), arr.size()-1});
        }
        else
        {
            if(pq.empty())
            {
                std::cout << 0 << '\n';
            }
            else
            {
                std::cout << arr[pq.top().second] <<'\n';
                pq.pop();
            }
        }
    }
	return 0;
}