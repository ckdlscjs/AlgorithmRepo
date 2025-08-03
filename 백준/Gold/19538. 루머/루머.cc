/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, M, dist[200'005];
bool chks[200'005];
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
        chks[val] = true;
        if(graph[val].size())
            q.push(val);
    }
    for(int i = 1; q.size(); i++)
    {
        std::queue<int> nq;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            for(const auto& iter : graph[cur])
            {
                if(chks[iter]) continue;
                int chkcount = 0;
                for(const auto& neig : graph[iter])
                    if(chks[neig]) chkcount++;
                if(chkcount >= graph[iter].size() / 2)
                    nq.push(iter); 
            }
        }
        while(nq.size())
        {
            auto cur = nq.front();
            nq.pop();
            if(chks[cur]) continue;
            dist[cur] = i;
            chks[cur] = true;
            q.push(cur);
        }
    }
    for(int i = 1; i <= N; i++) std::cout << dist[i] << ' ';
	return 0;
}

