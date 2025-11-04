#include <bits/stdc++.h>
using namespace std;
//0, 1
std::vector<int> Check(const std::vector<std::vector<int>>& arr, int y, int x, int depth)
{
    if(depth <= 0) return {!arr[y][x], arr[y][x]};
    auto lylx = Check(arr, y, x, depth/2);
    auto lyrx = Check(arr, y, x + depth, depth/2);
    auto rylx = Check(arr, y + depth, x, depth/2);
    auto ryrx = Check(arr, y + depth, x + depth, depth/2);
    if
        (
            lylx[0] == lyrx[0] &&
            lyrx[0] == rylx[0] &&
            rylx[0] == ryrx[0] &&
            lylx[1] == lyrx[1] &&
            lyrx[1] == rylx[1] &&
            rylx[1] == ryrx[1] &&
            ((lylx[0] == 0 && lylx[1] == 1) ||
            (lylx[0] == 1 && lylx[1] == 0))
        )
        return lylx;
    return {lylx[0] + lyrx[0] + rylx[0] + ryrx[0], lylx[1] + lyrx[1] + rylx[1] + ryrx[1]};
}
vector<int> solution(vector<vector<int>> arr) 
{
    return Check(arr, 0, 0, arr.size()/2);
}