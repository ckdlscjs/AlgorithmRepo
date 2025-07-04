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
	    std::vector<int> parents(N+1, 0);
	    for(int i = 1; i <= N; i++) parents[i] = i;
	    std::function<int(int)> Find = [&](int node)->int{
	        if(parents[node] == node) return node;
	        return node = Find(parents[node]);
	    };
	    std::function<void(int, int)> Union = [&](int node1, int node2)->void
	    {
	        int root1 = Find(node1);
	        int root2 = Find(node2);
	        if(root1 == root2) return;
	        if(root1 < root2) parents[root2] = root1;
	        else parents[root1] = root2;
	    };
	    for(int m = 0; m < M; m++)
	    {
	        int A, B;
	        std::cin >> A >> B;
	        if(Find(A) == Find(B))
	        {
	            Union(0, A);
	        }
	        else Union(A, B);
	    }
	    
	    int res = 0;
	    for(int i = 1; i <= N; i++)
	        if(parents[i] == i) res++;
	    std::cout << "Case " <<cnt<<": ";
	    if(res > 1) std::cout <<"A forest of "<<res<<" trees."<<'\n';
	    else if(res == 1) std::cout <<"There is one tree." << '\n';
	    else std::cout <<"No trees." << '\n';
	}
	return 0;
}

