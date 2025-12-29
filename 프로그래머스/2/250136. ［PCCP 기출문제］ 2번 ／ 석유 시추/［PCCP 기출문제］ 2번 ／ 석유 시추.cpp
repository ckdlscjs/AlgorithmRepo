#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
std::vector<int> amounts;
std::vector<std::vector<int>> arr;
int DFS(const std::vector<std::vector<int>>& land, const int area, int i, int j)
{
    int ret = 1;
    arr[i][j] = area;
    for(int dir = 0; dir < 4; dir++)
    {
        int ny = i + dy[dir];
        int nx = j + dx[dir];
        if(ny < 0 || nx < 0 || ny >= land.size() || nx >= land[0].size()) continue;
        if(land[ny][nx] == 0 || arr[ny][nx] != -1) continue;
        ret += DFS(land, area, ny, nx);
    }
    return ret;
}
int solution(vector<vector<int>> land) 
{
    arr.resize(land.size(), std::vector<int>(land[0].size(), -1));
    for(int i = 0; i < land.size(); i++)
    {
        for(int j = 0; j < land[i].size(); j++)
        {
            if(land[i][j] == 0) continue;
            if(arr[i][j] != -1) continue;
            amounts.push_back(DFS(land, amounts.size(), i, j));
        }
    }
    int answer = 0;
    for(int j = 0; j < land[0].size(); j++)
    {
        std::unordered_set<int> idxs;
        int sum = 0;
        for(int i = 0; i < land.size(); i++)
        {
            if(arr[i][j] == -1) continue;
            idxs.insert(arr[i][j]);
        }
        for(const auto& iter : idxs)
            sum += amounts[iter]; 
        answer = std::max(answer, sum);
    }
    return answer;
}