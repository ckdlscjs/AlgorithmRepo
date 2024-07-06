#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};
std::map<char, int> dir;
bool arr[15][15][4];
int solution(string dirs) 
{   
    dir['U'] = 0;
    dir['D'] = 1;
    dir['R'] = 2;
    dir['L'] = 3;
    int y = 5, x = 5;
    int count = 0;
    for(int i = 0; i < dirs.size(); i++)
    {
        int direction = dir[dirs[i]];
        int cy = y, cx = x;
        int ny = y + dy[dir[dirs[i]]];
        int nx = x + dx[dir[dirs[i]]];
        std::cout << ny << ' ' << nx << ", ";
        if(ny < 0 || nx < 0 || ny > 10 || nx > 10)
            continue;
        y = ny;
        x = nx;
        if(direction < 2)
        {
            if(arr[cy][cx][direction] || arr[ny][nx][std::abs(direction-1)])
                continue;
            arr[cy][cx][direction] = true;
            arr[ny][nx][std::abs(direction-1)] = true;
        }
        else
        {
            if(arr[cy][cx][direction] || arr[ny][nx][std::abs(direction-3) + 2])
                continue;
            arr[cy][cx][direction] = true;
            arr[ny][nx][std::abs(direction-3) + 2] = true;
        }
        count++;
        std::cout << cy << ' ' <<cx << "->" << ny << ' ' << nx <<'\n';
    }
    return count;
}