#include <bits/stdc++.h>
const int dy[] = {1, -1, 0 ,0};
const int dx[] = {0, 0, -1, 1};
std::map<std::string, int> dir;
using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    dir["up"] = 0;
    dir["down"] = 1;
    dir["left"] = 2;
    dir["right"] = 3;
    std::vector<int> answer{0, 0};
    for(const auto& str : keyinput)
    {
        int ny = answer[1] + dy[dir[str]];
        int nx = answer[0] + dx[dir[str]];
        if(ny < -board[1]/2 || ny > board[1]/2 || nx < -board[0] / 2 || nx > board[0]/2)
            continue;
        answer[0] = nx;
        answer[1] = ny;
    }
    return answer;
}