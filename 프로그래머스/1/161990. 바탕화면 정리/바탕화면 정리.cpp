//https://school.programmers.co.kr/learn/courses/30/lessons/161990
#include <bits/stdc++.h>
using namespace std;
std::vector<int> y;
std::vector<int> x;
vector<int> solution(vector<string> wallpaper) 
{
    for(int i = 0; i < wallpaper.size(); i++)
    {
        for(int j = 0; j < wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j] != '#')
                continue;
            y.push_back(i);
            x.push_back(j);
        }
    }
    std::sort(y.begin(), y.end(), std::less<>());
    std::sort(x.begin(), x.end(), std::less<>());
    return {y[0], x[0], *y.rbegin() + 1, *x.rbegin()+1};
}