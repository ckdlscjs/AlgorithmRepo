#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
vector<int> solution(vector<vector<string>> places) 
{
    vector<int> answer;
    for(const auto& iter : places)
    {
        bool chk = true;
        for(int i = 0; i < iter.size() && chk; i++)
        {
            for(int j = 0; j < iter[0].size() && chk; j++)
            {
                if(iter[i][j] != 'P') continue;
                std::vector<std::vector<int>> dist(iter.size(), std::vector<int>(iter[0].size(), 0));
                std::queue<std::pair<int, int>> q;
                dist[i][j] = 1;
                q.push({i, j});
                while(q.size())
                {
                    int cy = q.front().first;
                    int cx = q.front().second;
                    q.pop();
                    if(dist[cy][cx] >= 2 && iter[cy][cx] == 'P')
                    {
                        chk = false;
                        break;
                    }
                    if(dist[cy][cx] >= 3) continue;
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int ny = cy + dy[dir];
                        int nx = cx + dx[dir];
                        if(ny < 0 || nx < 0 || ny >= iter.size() || nx >= iter[0].size() || dist[ny][nx] || iter[ny][nx] == 'X') continue;
                        dist[ny][nx] = dist[cy][cx] + 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
        answer.push_back(chk);
    }
    return answer;
}