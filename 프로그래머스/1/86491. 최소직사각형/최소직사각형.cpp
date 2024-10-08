//https://school.programmers.co.kr/learn/courses/30/lessons/86491
#include <bits/stdc++.h>
int width, height;
using namespace std;
int solution(vector<vector<int>> sizes) 
{
    for(const auto& iter : sizes)
    {
        int large = std::max(iter[0], iter[1]);
        int small = std::min(iter[0], iter[1]);
        width = std::max(width, large);
        height = std::max(height, small);
    }
    return width * height;
}