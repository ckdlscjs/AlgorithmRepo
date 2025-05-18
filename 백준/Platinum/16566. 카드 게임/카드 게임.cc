#include <bits/stdc++.h>
using namespace std;

int N, M, K, val, parents[4'000'005], arr_m[4'000'005];
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
int Find(int node)
{
    if(parents[node] == 0) return node;
    return parents[node] = Find(parents[node]);
}
void Union(int node1, int node2)
{
    int root1 = Find(node1);
    int root2 = Find(node2);
    if(root1 != root2) 
        parents[root1] = root2;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> M >> K;
    for(int m = 0; m < M; m++) std::cin >> arr_m[m];
    std::sort(arr_m, arr_m + M);
    for(int k = 0; k < K; k++)
    {
        std::cin >> val;
        int lo = -1, hi = M;
        while(lo + 1 < hi)
        {
            int mid = (lo + hi) / 2;
            if(val < arr_m[mid]) hi = mid;
            else lo = mid;
        }
        hi = Find(hi);
        std::cout << arr_m[hi] << '\n';
        Union(hi, hi+1);
    }
    return 0;
}
