#include <bits/stdc++.h>
using namespace std;
int N, M, a, b, dist[502], res;
std::vector<int> graph[502];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> M;
    for(int m = 0; m < M; m++)
    {
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    std::queue<int> q;
    q.push(1);
    dist[1] = 1;
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        for(const auto& iter : graph[cur])
        {
            if(dist[iter]) continue;
            q.push(iter);
            dist[iter] = dist[cur]+1;
        }
    }
    for(int i = 2; i <= N; i++)
        if(dist[i] != 0 && dist[i] <= 3)
            res++;
    std::cout << res;
    return 0;
}
