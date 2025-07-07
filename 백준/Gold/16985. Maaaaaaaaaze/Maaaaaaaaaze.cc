/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
const int INF = 25*25*25+1;
const int dz[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dx[] = {0, 0, 0, 0, -1, 1};
int maze[5][4][5][5], res = INF;
void rotateCW(int (*idxarr)[5][5], int idx, int (*arr)[5])
{
    int temp[5][5];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++) 
            temp[j][5-i-1] = arr[i][j];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            idxarr[idx][i][j] = temp[i][j];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    for(int idx = 0; idx < 5; idx++)
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                std::cin >> maze[idx][0][i][j];
    for(int i = 0; i < 5; i++)
        for(int idx = 1; idx < 4; idx++)
            rotateCW(maze[i], idx, maze[i][0+idx-1]);
       

    int chk[] = {0, 1, 2, 3, 4};
    do
    {
        for(int i0 = 0; i0 < 4 && res > 12; i0++)
        {
            for(int i1 = 0; i1 < 4 && res > 12; i1++)
            {
                for(int i2 = 0; i2 < 4 && res > 12; i2++)
                {
                    for(int i3 = 0; i3 < 4 && res > 12; i3++)
                    {
                        for(int i4 = 0; i4 < 4; i4++)
                        {
                            if(maze[chk[0]][i0][0][0] == 0 || maze[chk[4]][i4][4][4] == 0) continue;
                            int dist[5][5][5];
                            std::memset(dist, 0, sizeof(dist));
                            std::queue<std::tuple<int, int, int>> q;
                            q.push({0, 0, 0});
                            dist[0][0][0] = 1;
                            while(q.size())
                            {
                                auto cur = q.front();
                                q.pop();
                                int cz = std::get<0>(cur);
                                int cy = std::get<1>(cur);
                                int cx = std::get<2>(cur);
                                for(int dir = 0; dir < 6; dir++)
                                {
                                    int nz = cz + dz[dir];
                                    int ny = cy + dy[dir];
                                    int nx = cx + dx[dir];
                                    if(nz < 0 || ny < 0 || nx < 0 || nz >= 5 || ny >= 5 || nx >= 5 || dist[nz][ny][nx]) continue;
                                    if(nz == 0 && maze[chk[nz]][i0][ny][nx] == 0) continue;
                                    else if(nz == 1 && maze[chk[nz]][i1][ny][nx] == 0) continue;
                                    else if(nz == 2 && maze[chk[nz]][i2][ny][nx] == 0) continue;
                                    else if(nz == 3 && maze[chk[nz]][i3][ny][nx] == 0) continue;
                                    else if(nz == 4 && maze[chk[nz]][i4][ny][nx] == 0) continue;
                                    q.push({nz, ny, nx});
                                    dist[nz][ny][nx] = dist[cz][cy][cx] + 1;
                                }
                            }
                            if(dist[4][4][4] != 0)
                                res = std::min(res, dist[4][4][4]-1);
                        }
                    }
                }
            }
        }
    }while(std::next_permutation(chk, chk+5) && res > 12);
    std::cout << (res >= INF ? -1 : res);
	return 0;
}

