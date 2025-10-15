#include <bits/stdc++.h>
using namespace std;
std::unordered_map<char, std::vector<int>> D;
std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> chks;
int solution(string dirs) 
{
    D['U'] = {1, 0};
    D['D'] = {-1, 0};
    D['R'] = {0, 1};
    D['L'] = {0, -1};
    int answer = 0;
    int y = 0, x = 0;
    for(const auto& dir : dirs)
    {
        int sy = y;
        int sx = x;
        int ny = y + D[dir][0];
        int nx = x + D[dir][1];
        if(ny < -5 || nx < -5 || ny > 5 || nx > 5) continue;
        chks.insert({{sy, sx}, {ny, nx}});
        chks.insert({{ny, nx}, {sy, sx}});
        y = ny;
        x = nx;
    }
    
    return chks.size() / 2;
}