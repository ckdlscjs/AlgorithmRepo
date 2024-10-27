//https://school.programmers.co.kr/learn/courses/30/lessons/68936
#include <bits/stdc++.h>
using namespace std;
std::vector<int> Check(const std::vector<std::vector<int>>& arr, int n, int y, int x)
{
    if(n <= 1)
        return {arr[y][x] ? 0 : 1, arr[y][x] ? 1 : 0};
    std::vector<int> lu = Check(arr, n/2, y, x);
    std::vector<int> ru = Check(arr, n/2, y, x + n/2);
    std::vector<int> ld = Check(arr, n/2, y + n/2, x);
    std::vector<int> rd = Check(arr, n/2, y + n/2, x + n/2);
    if(lu == ru && ru == ld && ld == rd && ((lu[0] == 0 && lu[1] == 1) ||(lu[0] == 1 && lu[1] == 0)))
       return lu;
    else
       return {lu[0] + ru[0] + ld[0] + rd[0], lu[1] + ru[1] + ld[1] + rd[1]};
}
vector<int> solution(vector<vector<int>> arr) 
{
    return Check(arr, arr.size(), 0, 0);
}