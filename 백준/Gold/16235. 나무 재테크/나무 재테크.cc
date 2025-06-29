/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
const int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int N, M, K, arr[12][12], A[12][12], res;
std::vector<std::pair<int, int>> trees[12][12]; //level, cnt
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M >> K;
	
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin >> A[i][j];
            arr[i][j] = 5;
        }
    }
        
    for(int m = 0; m < M; m++)
    {
        int y, x, z;
        std::cin >> y >> x >> z;
        y--; x--; 
        trees[y][x].push_back({z, 1});
    }
    for(int k = 0; k < K; k++)
    {
        //봄,여름,겨울
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                int adds = A[i][j];
                for(int idx = trees[i][j].size()-1; idx >= 0; idx--)
                {
                    int level = trees[i][j][idx].first;
                    int cnt = trees[i][j][idx].second;
                    if(level * cnt <= arr[i][j])
                    {
                        arr[i][j] -= level*cnt;
                        trees[i][j][idx].first += 1;
                    }
                    else
                    {
                        int alives = arr[i][j] / level;
                        int deads = cnt - alives;
                        int cur = idx + 1;
                        if(alives > 0)
                        {
                            arr[i][j] -= level*alives;
                            trees[i][j][idx].first += 1;
                            trees[i][j][idx].second = alives;
                            cur--;
                        }
                        //이보다 앞의 나무들은 전부다 양분이 모잘라 죽는나무가됨
                        adds += deads * (level / 2);
                        for(--idx; idx >= 0; idx--)
                            adds += (trees[i][j][idx].first / 2)*trees[i][j][idx].second;
                        trees[i][j].erase(trees[i][j].begin(), trees[i][j].begin() + cur);
                    }
                }
                arr[i][j] += adds;
            }
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                for(const auto& t : trees[i][j])
                {
                    if(t.first % 5) continue;
                    for(int dir = 0; dir < 8; dir++)
                    {
                        int ny = i + dy[dir];
                        int nx = j + dx[dir];
                        if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                        if(trees[ny][nx].size() && trees[ny][nx].back().first == 1) trees[ny][nx].back().second += t.second;
                        else trees[ny][nx].push_back({1, t.second});
                    }
                }
            }
        }
    } 
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int idx = trees[i][j].size()-1; idx >= 0; idx--)
                res += trees[i][j][idx].second;
        }
    }
    std::cout << res;
	return 0;
}
