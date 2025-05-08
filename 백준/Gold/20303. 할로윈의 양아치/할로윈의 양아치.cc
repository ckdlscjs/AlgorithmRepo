#include <bits/stdc++.h>
using namespace std;
int N, M, K, c[30'005], parents[30'005], sizes[30'005], dp[3'005], a, b;
int Find(int node)
{
    if(parents[node] == node) return node;
    return parents[node] = Find(parents[node]);
}
void Union(int node1, int node2)
{
    int root1 = Find(node1);
    int root2 = Find(node2);
    if(root1 == root2) return;
    if(root1 < root2) parents[root2] = root1;
    else parents[root1] = root2;
}
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N >> M >> K;
    for(int n = 1; n <= N; n++)
    {
        std::cin >> c[n];
        parents[n] = n;
        sizes[n] = 1;
    }
    for(int m = 0; m < M; m++)
    {
        std::cin >> a >> b;
        Union(a, b);
    }
    for(int n = 1; n <= N; n++)
    {
        if(parents[n] != n)
        {
            int parent = Find(n);
            sizes[parent] += sizes[n];
            c[parent] += c[n];
        }
    }
    for(int n = 1; n <= N; n++)
    {
        if(Find(n) != n) continue;
        for(int k = K-1; k - sizes[n] >= 0; k--)
        {
            dp[k] = std::max(dp[k], dp[k - sizes[n]] + c[n]);
        }
    }
    std::cout << dp[K-1];
    return 0;
}