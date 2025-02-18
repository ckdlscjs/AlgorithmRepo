#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
int solution(vector<string> storage, vector<string> requests) 
{  
    int answer = storage.size() * storage[0].size();
    std::vector<std::vector<char>> areas(storage.size()+2, std::vector<char>(storage[0].size()+2, '0'));
    for(int i = 0; i < storage.size(); i++)
    {
        for(int j = 0; j < storage[0].size(); j++)
        {
            areas[i+1][j+1] = storage[i][j];
        }
    }
    for(const auto& req : requests)
    {
        if(req.size() <= 1)
        {
            std::vector<std::vector<bool>> visited(storage.size()+2, std::vector<bool>(storage[0].size()+2, false));
            std::set<std::pair<int, int>> erases;
            std::queue<std::pair<int, int>> q;
            q.push({0, 0});
            visited[0][0] = true;
            while(q.size())
            {
                auto cur = q.front();
                q.pop();
                for(int dir = 0; dir < 4; dir++)
                {
                    int ny = cur.first + dy[dir];
                    int nx = cur.second + dx[dir];
                    if(ny < 0 || nx < 0 || ny >= areas.size() || nx >= areas[0].size() || visited[ny][nx]) continue;
                    if(areas[ny][nx] == '0')
                    {
                        q.push({ny, nx});
                        visited[ny][nx] = true;
                    }
                    else if(areas[ny][nx] == req[0])
                    {
                        erases.insert({ny, nx});
                    }
                }
            }
            answer -= erases.size();
            for(const auto& iter : erases)
                areas[iter.first][iter.second] = '0';
        }
        else
        {
            for(int i = 1; i <= storage.size(); i++)
            {
                for(int j = 1; j <= storage[0].size(); j++)
                {
                    if(areas[i][j] == req[0])
                    {
                        areas[i][j] = '0';
                        answer--;
                    }
                }
            }
        }
    }
    return answer;
}