/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, M, cnt;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	while(std::cin >> N >> M)
	{
	    cnt++;
	    if(N == 0 && M == 0) break;
	    std::vector<std::vector<int>> graph(N+1);
	    std::vector<bool> visited(N+1, false);
	    for(int m = 0; m < M; m++)
	    {
	        int A, B;
	        std::cin >> A >> B;
	        graph[A].push_back(B);
	        graph[B].push_back(A);
	    }
	    std::function<bool(int, int)> DFS = [&](int prv, int cur)->bool{
	        visited[cur] = true;
	        for(const auto& iter : graph[cur])
	        {
	            if(prv == iter) continue;
	            if(visited[iter]) return false;
	            if(!DFS(cur, iter)) return false;
	        }
	        return visited[cur];
	    };
	    int res = 0;
	    
	    for(int i = 1; i <= N; i++)
	    {
	        if(visited[i]) continue;
	        if(DFS(-1, i)) res++;
	    }
	    
	    std::cout << "Case " <<cnt<<": ";
	    if(res > 1) std::cout <<"A forest of "<<res<<" trees."<<'\n';
	    else if(res == 1) std::cout <<"There is one tree." << '\n';
	    else std::cout <<"No trees." << '\n';
	}
	return 0;
}

