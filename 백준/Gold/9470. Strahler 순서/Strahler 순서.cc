/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int T, K, M, P;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> T;
    for(int t = 0; t < T; t++)
    {
        std::cin >> K >> M >> P;
        std::vector<std::pair<int, int>> in_strahler(M+1);
        std::vector<int> strahler(M+1, 0);
        std::vector<int> indegree(M+1, 0);
        std::vector<int> graph[1'005];
        int max_strahler = 0;
        for(int p = 0; p < P; p++)
        {
            int A, B;
            std::cin >> A >> B;
            graph[A].push_back(B);
            indegree[B]++;
        }
        std::queue<int> q;
        for(int i = 1; i <= M; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                in_strahler[i] = std::make_pair(1, 1);
            }
        }
        for(int i = 1; i <= M; i++)
        {
            auto cur = q.front();
            q.pop();
            strahler[cur] = in_strahler[cur].second >= 2 ? in_strahler[cur].first + 1 : in_strahler[cur].first;
            //std::cout << cur << ' ' << strahler[cur] << '\n';
            max_strahler = std::max(max_strahler, strahler[cur]);
            for(const auto& iter : graph[cur])
            {
                indegree[iter]--;
                if(in_strahler[iter].first <= strahler[cur])
                {
                    if(in_strahler[iter].first < strahler[cur])
                    {
                        in_strahler[iter].first = strahler[cur];
                        in_strahler[iter].second = 0;
                    }
                    in_strahler[iter].second++;
                }
                if(indegree[iter] <= 0)
                {
                    q.push(iter);
                }
            }
        }
        std::cout << K << ' ' << max_strahler << '\n';
    }
	return 0;
}

