#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<string> keyinput, vector<int> board) 
{
    std::unordered_map<std::string, std::pair<int, int>> inputs;
    inputs["up"] = {1, 0};
    inputs["down"] = {-1, 0};
    inputs["left"] = {0, -1};
    inputs["right"] = {0, 1};
    int y = 0, x = 0;
    for(const auto& iter : keyinput)
    {
        int ny = y + inputs[iter].first;
        int nx = x + inputs[iter].second;
        if(ny <  -board[1] / 2 || nx < -board[0] / 2 || ny > board[1]/2 || nx > board[0]/2)
            continue;
        y = ny;
        x = nx;
    }
    return {x, y};
}