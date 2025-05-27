/*
1.접근방식:


2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, M, A, B, dist[20'005];
std::vector<int> graph[20'005];
std::map<int, std::set<int>> chks;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for(int m = 0; m < M; m++)
    {
        std::cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    std::queue<int> q;
    dist[1] = 1;
    q.push(1);
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        for(const auto& iter : graph[cur])
        {
            if(dist[iter]) continue;
            dist[iter] = dist[cur] + 1;
            chks[dist[iter]-1].insert(iter);
            q.push(iter);
        }
    }
    std::cout << *((*chks.rbegin()).second.begin()) << ' ' << (*chks.rbegin()).first << ' ' << (*chks.rbegin()).second.size();
    return 0;
}
