//https://school.programmers.co.kr/learn/courses/30/lessons/152995
#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> scores) 
{
    std::vector<int> p = scores[0];
    std::sort(scores.begin(), scores.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    });
    int answer = 1;
    int maxval = scores[0][1];
    for(const auto & iter : scores)
    {
        if(maxval <= iter[1])
        {
            maxval = iter[1];
            if(iter[0] + iter[1] > p[0] + p[1])
                answer++;
        }
        else
        {
            if(iter[0] == p[0] && iter[1] == p[1]) return -1;
        }
    }
    
    return answer;
}