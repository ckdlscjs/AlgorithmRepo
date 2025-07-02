/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, A, B;
std::vector<int> graph[52];
std::map<int, std::vector<int>> results;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
    while(std::cin >> A >> B)
    {
        if(A == -1 && B == -1) break;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    for(int i = 1; i <= N; i++)
    {
        int maxdist = 0;
        std::vector<int> dist(N+1, 0);
        dist[i] = 1;
        std::queue<int> q;
        q.push(i);
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            maxdist = std::max(maxdist, dist[cur]-1);
            for(const auto& iter : graph[cur])
            {
                if(dist[iter]) continue;
                q.push(iter);
                dist[iter] = dist[cur] + 1;
            }
        }
        results[maxdist].push_back(i);
    }
    std::cout << results.begin()->first << ' ' << results.begin()->second.size() << '\n';
    for(const auto& iter : results.begin()->second)
        std::cout << iter << ' ';
	return 0;
}

