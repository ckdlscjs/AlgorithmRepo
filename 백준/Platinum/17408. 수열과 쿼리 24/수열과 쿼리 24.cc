#include <bits/stdc++.h>
using namespace std;
using pll = std::pair<long long, long long>;
long long N, M, order, a, b;
pll tree[4*100'005];
pll Update(int idx, long long val, int s, int e, int cur)
{
    if(idx < s || e < idx) return tree[cur];
    if(idx <= s && e <= idx) return tree[cur] = std::make_pair(val, 0);
    int mid = (s + e) / 2;
    std::vector<long long> ret;
    auto ll = Update(idx, val, s, mid, cur*2);
    auto rr = Update(idx, val, mid+1, e, cur*2+1);
    ret.push_back(ll.first); ret.push_back(ll.second);
    ret.push_back(rr.first); ret.push_back(rr.second);
    std::sort(ret.begin(), ret.end(), std::greater<>());
    return tree[cur] = std::make_pair(ret[0], ret[1]);
}
pll Query(int l, int r, int s, int e, int cur)
{
    if(r < s || e < l) return std::make_pair(0, 0);
    if(l <= s && e <= r) return tree[cur];
    int mid = (s + e) / 2;
    std::vector<long long> ret;
    auto ll = Query(l, r, s, mid, cur*2);
    auto rr = Query(l, r, mid+1, e, cur*2+1);
    ret.push_back(ll.first); ret.push_back(ll.second);
    ret.push_back(rr.first); ret.push_back(rr.second);
    std::sort(ret.begin(), ret.end(), std::greater<>());
    return std::make_pair(ret[0], ret[1]);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 1; n <= N; n++)
    {
        std::cin >> b;
        Update(n, b, 1, N, 1);
    }
    std::cin >> M;
    for(int m = 0; m < M; m++)
    {
        std::cin >> order >> a >> b;
        if(order == 1)
        {
            Update(a, b, 1, N, 1);
        }
        else
        {
            pll ret = Query(a, b, 1, N, 1);
            std::cout << ret.first + ret.second << '\n';
        }
    }
    return 0;
}