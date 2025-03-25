#include <bits/stdc++.h>
int T, N, y, x;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    for(int t = 0; t < T; t++)
    {
        std::cin >> N;
        std::vector<std::pair<int, int>> poss;
        std::vector<bool> visited(N+2, false);
        std::vector<std::vector<int>> graph(N+2);
        for(int n = 0; n < N + 2; n++)
        {
            std::cin >> y >> x;
            poss.push_back({y, x});
        }
        for(int i = 0; i < N+1; i++)
        {
            for(int j = i + 1; j < N + 2; j++)
            {
                int dist = std::abs(poss[i].first - poss[j].first) + std::abs(poss[i].second - poss[j].second);
                if(dist > 1000) continue;
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
        visited[0] = true;
        std::queue<int> q;
        q.push(0);
        while(q.size())
        {
            int cur = q.front();
            q.pop();
            for(const auto& iter : graph[cur])
            {
                if(visited[iter]) continue;
                visited[iter] = true;
                q.push(iter);
            }
        }
        std::cout << (visited[N+1] ? "happy" : "sad") << '\n';
    }
	return 0;
}