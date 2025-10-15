#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};
std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> checks; 
std::unordered_map<char, int> dir;
int y, x, answer;
int solution(string dirs) 
{
    dir['U'] = 0;dir['D'] = 1;dir['R'] = 2;dir['L'] = 3;
    for(const auto& iter : dirs)
    {
        int ny = y + dy[dir[iter]];
        int nx = x + dx[dir[iter]];
        if(ny < -5 || nx < -5 || ny > 5 || nx > 5)
            continue;
        if(checks.find({{y, x}, {ny, nx}}) == checks.end())
            answer++;
        checks.insert({{y, x}, {ny, nx}});
        checks.insert({{ny, nx}, {y, x}});
        y = ny;
        x = nx;
    }
    return answer;
}