/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, M, arr[6][6];
const int dy[][2] = {{0, 1}, {-1, 0}, {-1, 0}, {0, 1}};
const int dx[][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
bool visited[6][6];
int Check(int y, int x)
{
    if(y >= N) return 0;
    if(x >= M) return Check(y+1, 0);
    if(visited[y][x]) return Check(y, x+1);
    int ret = 0;
    for(int dir = 0; dir < 4; dir++)
    {
        int ny0 = y + dy[dir][0];
        int nx0 = x + dx[dir][0];
        if(ny0 < 0 || nx0 < 0 || ny0 >= N || nx0 >= M || visited[ny0][nx0]) continue;
        int ny1 = y + dy[dir][1];
        int nx1 = x + dx[dir][1];
        if(ny1 < 0 || nx1 < 0 || ny1 >= N || nx1 >= M || visited[ny1][nx1]) continue;
        visited[ny0][nx0] = visited[ny1][nx1] = visited[y][x] = true;
        ret = std::max(ret, Check(y, x+1) + arr[ny0][nx0] + arr[ny1][nx1] + arr[y][x] * 2);
        visited[ny0][nx0] = visited[ny1][nx1] = visited[y][x] = false;
    }
    ret = std::max(ret, Check(y, x+1));
    return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N >> M;
    for(int n = 0; n < N; n++)
        for(int m = 0; m < M; m++)
            std::cin >> arr[n][m];
    std::cout << Check(0, 0);
	return 0;
}
