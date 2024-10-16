//https://school.programmers.co.kr/learn/courses/30/lessons/12982
#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> d, int budget) 
{
    std::sort(d.begin(), d.end(), std::less<>());
    for(int i = 0; i < d.size(); i++)
    {
        budget -= d[i];
        if(budget < 0)
            return i;
    }
    return d.size();
}