#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int solution(vector<string> storage, vector<string> requests) 
{
    for(const auto& req : requests)
    {
        std::unordered_map<std::string, std::vector<std::pair<int, int>>> alps;
        if(req.size() <= 1)
        {
            std::vector<std::vector<bool>> visited(storage.size(), std::vector<bool>(storage[0].size(), false));
            std::queue<std::pair<int, int>> q;
            for(int i = 0; i < storage.size(); i++)
            {
                for(int j = 0; j < storage[i].size(); j++)
                {
                    if(i == 0 || j == 0 || i >= storage.size()-1 || j >= storage[0].size()-1)
                    {
                        q.push({i, j});
                        visited[i][j] = true;
                    }
                }
            }
            while(q.size())
            {
                auto cur = q.front();
                q.pop();
                int cy = cur.first;
                int cx = cur.second;
                if(storage[cy][cx] != '0') alps[std::string(1, storage[cy][cx])].push_back({cy, cx});
                else
                {
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int ny = cy + dy[dir];
                        int nx = cx + dx[dir];
                        if(ny < 0 || nx < 0 || ny >= storage.size() || nx >= storage[0].size()) continue;
                        if(visited[ny][nx]) continue;
                        visited[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
            }
        }
        else
        {
            for(int i = 0; i < storage.size(); i++)
            {
                for(int j = 0; j < storage[i].size(); j++)
                {
                    if(storage[i][j] == '0') continue;
                    std::string cur(1, storage[i][j]);
                    alps[cur + storage[i][j]].push_back({i, j});
                }
            }
        }
        for(const auto& iter : alps[req])
                storage[iter.first][iter.second] = '0';
    }
    int answer = 0;
    for(int i = 0; i < storage.size(); i++)
    {
        for(int j = 0; j < storage[i].size(); j++)
        {
            //std::cout << storage[i][j] << ' ';
            if(storage[i][j] != '0')
                answer++;
        }
        //std::cout << '\n';
    }        
    return answer;
}