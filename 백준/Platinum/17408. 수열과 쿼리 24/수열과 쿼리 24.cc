#include <bits/stdc++.h>
using namespace std;
using pll = std::pair<long long, long long>;
long long N, M, arr[100'005], order, a, b;
pll tree[4*100'005];

pll MaxPair(pll a, pll b) 
{
    std::vector<long long> v = {a.first, a.second, b.first, b.second};

    long long first = 0, second = 0;
    for (long long x : v) 
    {
        if (x >= first) 
        {
            second = first;
            first = x;
        } 
        else if (x > second) 
        {
            second = x;
        }
    }
    return {first, second};
}

pll Init(int s, int e, int cur)
{
    if(s >= e) return tree[cur] = std::make_pair(arr[s], 0);
    int mid = (s + e) / 2;
    auto ll = Init(s, mid, cur*2);
    auto rr = Init(mid+1, e, cur*2+1);
    return tree[cur] = MaxPair(ll, rr);
}
pll Update(int idx, long long val, int s, int e, int cur)
{
    if(idx < s || e < idx) return tree[cur];
    if(idx <= s && e <= idx) return tree[cur] = std::make_pair(val, 0);
    int mid = (s + e) / 2;
    auto ll = Update(idx, val, s, mid, cur*2);
    auto rr = Update(idx, val, mid+1, e, cur*2+1);
    return tree[cur] = MaxPair(ll, rr);
}
pll Query(int l, int r, int s, int e, int cur)
{
    if(r < s || e < l) return std::make_pair(0, 0);
    if(l <= s && e <= r) return tree[cur];
    int mid = (s + e) / 2;
    auto ll = Query(l, r, s, mid, cur*2);
    auto rr = Query(l, r, mid+1, e, cur*2+1);
    return MaxPair(ll, rr);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 1; n <= N; n++) std::cin >> arr[n];
    Init(1, N, 1);
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