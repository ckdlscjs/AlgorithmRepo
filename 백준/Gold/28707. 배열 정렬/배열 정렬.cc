#include <bits/stdc++.h>
using namespace std;
#define piv std::pair<int, std::vector<int>>
#define tiii std::tuple<int, int, int>
const int INF = 987654321;
int N, M, l, r, c;
std::vector<int> arr;
std::vector<tiii> edges;
std::map<std::vector<int>, int> costs;
std::priority_queue<piv, std::vector<piv>, std::greater<piv>> pq;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    arr.resize(N);
    for(int n = 0; n < N; n++) std::cin >> arr[n];
    std::cin >> M;
    for(int m = 0; m < M; m++)
    {
        std::cin >> l >> r >> c;
        edges.push_back(std::make_tuple(l, r, c));
    }
    costs[arr] = 0;
    pq.push({0, arr});
    while(pq.size())
    {
        auto cur = pq.top(); pq.pop();
        if(cur.first > costs[cur.second]) continue;
        for(const auto& iter : edges)
        {
            l = std::get<0>(iter);
            r = std::get<1>(iter);
            c = std::get<2>(iter);
            std::vector<int> nxt = cur.second;
            std::swap(nxt[l-1], nxt[r-1]);
            if(costs.find(nxt) == costs.end()) costs[nxt] = INF;
            if(costs[cur.second] + c < costs[nxt])
            {
                costs[nxt] = costs[cur.second] + c;
                pq.push({costs[nxt], nxt});
            }
        }
    }
    std::sort(arr.begin(), arr.end());
    std::cout << (costs.find(arr) == costs.end() ? -1 : costs[arr]);
    return 0;
}
