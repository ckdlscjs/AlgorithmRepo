#include <bits/stdc++.h>
using namespace std;
int N, a, b;
std::vector<int> graph[52];
std::vector<int> dists[52];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    while(std::cin >> a >> b)
    {
        if(a == -1 && b == -1) break;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= N; i++)
    {
        int maxdist = 1;
        std::vector<int> dist(N+1, 0);
        std::queue<int> q;
        q.push(i);
        dist[i] = 1;
        while(q.size())
        {
            int cur = q.front();
            q.pop();
            for(const auto& iter : graph[cur])
            {
                if(dist[iter]) continue;
                q.push(iter);
                dist[iter] = dist[cur] + 1;
                maxdist = std::max(maxdist, dist[iter]);
            }
        }
        dists[maxdist-1].push_back(i);
    }
    for(int i = 1; i <= 52; i++)
    {
        if(dists[i].empty()) continue;
        std::cout << i << ' ' << dists[i].size() << '\n';
        for(const auto& iter : dists[i])
            std::cout << iter << ' ';
        return 0;
    }
    return 0;
}
