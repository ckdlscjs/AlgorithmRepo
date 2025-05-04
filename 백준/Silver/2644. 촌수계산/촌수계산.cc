#include <bits/stdc++.h>
using namespace std;
int N, A, B, M, x, y, depth[105], parent[105], res;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> A >> B >> M;
    for(int m = 0; m < M; m++)
    {
        std::cin >> x >> y;
        depth[y] += depth[x] + 1;
        parent[y] = x;
    }
    int rootA = A, rootB = B;
    while(parent[rootA] != 0) rootA = parent[rootA];
    while(parent[rootB] != 0) rootB = parent[rootB];
    if(rootA != rootB)
    {
        std::cout << -1;
        return 0;
    }
    rootA = A; rootB = B;
    while(depth[rootB] != depth[rootA])
    {
        if(depth[rootA] > depth[rootB]) rootA = parent[rootA];
        else rootB = parent[rootB];
        res++;
    }
    while(rootA != rootB)
    {
        rootA = parent[rootA];
        rootB = parent[rootB];
        res += 2;
    }
    std::cout << res;
    return 0;
}
