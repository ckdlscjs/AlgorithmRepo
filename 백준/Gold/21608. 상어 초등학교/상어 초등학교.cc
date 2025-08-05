/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
const int dy[] = {-1, 0, 0, 1};
const int dx[] = {0, -1, 1, 0};
int N, arr[22][22], res;
std::map<int, std::unordered_set<int>> chks;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N*N; n++)
    {
        int j, k;
        std::cin >> j;
        for(int c = 0; c < 4; c++)
        {
            std::cin >> k;
            chks[j].insert(k);
        }
        std::vector<std::tuple<int, int, int, int>> poss;
        for(int ii = N-1; ii >= 0; ii--)
        {
            for(int jj = N-1; jj >= 0; jj--)
            {
                if(arr[ii][jj]) continue;
                int cnt_likes = 0;
                int cnt_emptys = 0;
                for(int dir = 0; dir < 4; dir++)
                {
                    int ny = dy[dir] + ii;
                    int nx = dx[dir] + jj;
                    if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                    if(arr[ny][nx])
                    {
                        if(chks[j].find(arr[ny][nx]) != chks[j].end())
                            cnt_likes++;
                    }
                    else
                    {
                        cnt_emptys++;
                    }
                }
                poss.push_back({cnt_likes, cnt_emptys, ii, jj});
            }
        }
        std::sort(poss.begin(), poss.end(), [](std::tuple<int, int, int, int>& a, std::tuple<int, int, int, int>& b) -> bool {
            if(std::get<0>(a) == std::get<0>(b))
            {
                if(std::get<1>(a) == std::get<1>(b))
                {
                    if(std::get<2>(a) == std::get<2>(b))
                    {
                        return std::get<3>(a) < std::get<3>(b);
                    }
                    return std::get<2>(a) < std::get<2>(b);
                }
                return std::get<1>(a) > std::get<1>(b);
            }
            return std::get<0>(a) > std::get<0>(b);
        });
        int y = std::get<2>(poss[0]);
        int x = std::get<3>(poss[0]);
        arr[y][x] = j;
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            //std::cout << arr[i][j] << ' ';
            int cnt = 0;
            for(int dir = 0; dir < 4; dir++)
            {
                int ny = dy[dir] + i;
                int nx = dx[dir] + j;
                if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                if(chks[arr[i][j]].find(arr[ny][nx]) == chks[arr[i][j]].end()) continue;
                cnt++;
            }
            res += cnt >= 4 ? 1000 : cnt >= 3 ? 100 : cnt >= 2 ? 10 : cnt >= 1 ? 1 : 0; 
        }
        //std::cout << '\n';
    }
    std::cout << res;
	return 0;
}

