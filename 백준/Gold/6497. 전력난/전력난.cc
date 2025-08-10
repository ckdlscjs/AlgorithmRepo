/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int M, N;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    while(std::cin >> M >> N)
    {
        if(M == 0 && N == 0) return 0;
        std::vector<int> parents(M, -1);
        std::vector<int> ranks(M, 0);
        std::function<int(int)> Find = [&](int node)->int{
            if(parents[node] == -1) return node;
            return parents[node] = Find(parents[node]);
        };
        std::function<void(int, int)> Union = [&](int node1, int node2)->void{
            int root1 = Find(node1);
            int root2 = Find(node2);
            if(root1 == root2) return;
            if(ranks[root1] == ranks[root2]) ranks[root1]++;
            if(ranks[root1] > ranks[root2]) parents[root2] = root1;
            else parents[root1] = root2;
        };
        std::vector<std::tuple<int, int, int>> edges;
        int sum = 0;
        for(int n = 0; n < N; n++)
        {
            int x, y, z;
            std::cin >> x >> y >> z;
            edges.push_back({z, x, y});
            sum += z;
        }
        std::sort(edges.begin(), edges.end());
        for(const auto& iter : edges)
        {
            int z = std::get<0>(iter);
            int x = std::get<1>(iter);
            int y = std::get<2>(iter);
            if(Find(x) == Find(y)) continue;
            Union(x, y);
            sum -= z;
        }
        std::cout << sum << '\n';
    }
	return 0;
}

