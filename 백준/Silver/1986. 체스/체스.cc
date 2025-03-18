#include <bits/stdc++.h>
const int dqy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dqx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dky[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dkx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
using pii = std::pair<int, int>;
std::vector<pii> queens, knights, pawns;
int N, M, K, r, c, cnt;
bool visited[1005][1005];
bool area[1005][1005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
	std::cin >> N >> M;
	std::cin >> K;
	for(int k = 0; k < K; k++)
	{
	    std::cin >> r >> c;
	    queens.push_back({r, c});
	    visited[r][c] = true;
	    area[r][c] = true;
	}
	
	std::cin >> K;
	for(int k = 0; k < K; k++)
	{
	    std::cin >> r >> c;
	    knights.push_back({r, c});
	    visited[r][c] = true;
	    area[r][c] = true;
	}
	
	std::cin >> K;
	for(int k = 0; k < K; k++)
	{
	    std::cin >> r >> c;
	    pawns.push_back({r, c});
	    visited[r][c] = true;
	    area[r][c] = true;
	}
	for(const auto& iter : queens)
	{
	    for(int dir = 0; dir < 8; dir++)
	    {
	        int ny = iter.first + dqy[dir];
	        int nx = iter.second + dqx[dir];
	        while(1)
	        {
	            if(ny < 1 || nx < 1 || ny > N || nx > M || visited[ny][nx]) break;
	            area[ny][nx] = true;
	            ny += dqy[dir];
	            nx += dqx[dir];
	        }
	    }
	}
	
	for(const auto& iter : knights)
	{
	    for(int dir = 0; dir < 8; dir++)
	    {
	        int ny = iter.first + dky[dir];
	        int nx = iter.second + dkx[dir];
	        if(ny < 1 || nx < 1 || ny > N || nx > M || visited[ny][nx]) continue;
	        area[ny][nx] = true;
	    }
	}
	for(int i = 1; i <= N; i++)
	{
	    for(int j = 1; j <= M; j++)
	    {
	        //std::cout << (area[i][j] ? 'x' : 'o') << ' ';
	        cnt += area[i][j] ? 0 : 1;
	    }
	    //std::cout << '\n';
	}
	    
	        
	std::cout << cnt;
	return 0;
}