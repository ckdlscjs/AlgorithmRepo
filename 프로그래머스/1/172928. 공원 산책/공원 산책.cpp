#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
std::unordered_map<char, int> dirs;
vector<int> solution(vector<string> park, vector<string> routes) 
{
    dirs['E'] = 0;
    dirs['W'] = 1;
    dirs['S'] = 2;
    dirs['N'] = 3;
    for(int i = 0; i < park.size(); i++)
    {
        for(int j = 0; j < park[i].size(); j++)
        {
            if(park[i][j] !='S')
                continue;
            int y = i;
            int x = j;
            for(const auto& iter : routes)
            {
                bool chk = true;
                for(int cnt = 1; cnt <= iter[2]-'0'; cnt++)
                {
                    int ny = y + dy[dirs[iter[0]]]*cnt;
                    int nx = x + dx[dirs[iter[0]]]*cnt;
                    if(ny < 0 || nx < 0 || ny >= park.size() || nx >= park[i].size() || park[ny][nx] == 'X')
                    {
                        chk = false;
                        break;
                    }
                }
                if(chk)
                {
                    y += dy[dirs[iter[0]]]*(iter[2] -'0');
                    x += dx[dirs[iter[0]]]*(iter[2] -'0');
                }
            }
            return {y, x};
        }
    }
}