//https://school.programmers.co.kr/learn/courses/30/lessons/17682
#include <bits/stdc++.h>
using namespace std;
int solution(string dartResult) 
{
    std::pair<int, std::string> scores[3] = {{0, ""}, {0, ""}, {0, ""}};
    int idx = 0;
    for(int i = 0; i < dartResult.size(); i++)
    {
        if('0' <= dartResult[i] && dartResult[i] <= '9')
        {
            if(i - 1 > 0 && !('0' <= dartResult[i-1] && dartResult[i-1] <= '9')) idx++;
            scores[idx].first = scores[idx].first*10 + (dartResult[i]-'0');
        }
        else
        {
            scores[idx].second += dartResult[i];
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(const auto& iter : scores[i].second)
        {
            if(iter == 'S')
                scores[i].first = scores[i].first;
            else if(iter == 'D')
                scores[i].first = scores[i].first * scores[i].first;
            else if(iter == 'T')
                scores[i].first = scores[i].first * scores[i].first * scores[i].first;
            else if(iter == '*' && i <= 0)
                scores[i].first *= 2;
            else if(iter == '*' && i > 0)
                scores[i-1].first *=2, scores[i].first *= 2;
            else if(iter == '#')
                scores[i].first *= -1;
        }
    }
    
    return scores[0].first + scores[1].first + scores[2].first;
}