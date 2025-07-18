/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
const int INF = 205;
int N, M, dist[102][102], res = 205*100;
std::pair<int, int> lesss;
std::vector<int> graph[102];
void DFS(const int& st, int cur)
{
    for(const auto& iter : graph[cur])
    {
        if(dist[st][iter] != INF) continue;
        dist[st][iter] = dist[st][cur] + 1;
        DFS(st, iter);
    }
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N >> M;
    std::fill_n(&dist[0][0], 102*102, INF);
    for(int m = 0; m < M; m++)
    {
        int A, B;
        std::cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    for(int i = 1; i <= N; i++)
    {
        dist[i][i] = 0;
        DFS(i, i);
    }
    for(int i = N; i >= 1; i--)
    {
        for(int j = i-1; j >= 1; j--)
        {
            int cur = 0;
            for(int idx = 1; idx <= N; idx++)
                cur += 2*std::min(dist[idx][j], dist[idx][i]);
            if(cur <= res)
            {
                res = cur;
                lesss.first = j;
                lesss.second = i;
            }
        }
    }
    std::cout << lesss.first << ' ' << lesss.second << ' ' << res;
	return 0;
}

