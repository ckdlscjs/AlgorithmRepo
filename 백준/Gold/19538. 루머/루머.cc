/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, M, dist[200'005], cnts[200'005];
std::vector<int> graph[200'005];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N;
    for(int n = 1; n <= N; n++)
    {
        int val = 1;
        while(std::cin >> val)
        {
            if(val == 0) break;
            graph[n].push_back(val);
            graph[val].push_back(n);
        }
    }
    std::memset(dist, -1, sizeof(dist));
    std::cin >> M;
    std::queue<int> q;
    for(int m = 0; m < M; m++)
    {
        int val;
        std::cin >> val;
        dist[val] = 0;
        cnts[val] = graph[val].size();
        if(graph[val].size())
            q.push(val);
    }
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        for(const auto& iter : graph[cur])
        {
            if(cnts[iter] >= graph[iter].size()/2) continue;
            cnts[iter]++;
            if(cnts[iter] >= graph[iter].size()/2)
            {
                q.push(iter);
                dist[iter] = dist[cur]+1;
            }
        }
    }
    for(int i = 1; i <= N; i++) std::cout << dist[i] << ' ';
	return 0;
}

