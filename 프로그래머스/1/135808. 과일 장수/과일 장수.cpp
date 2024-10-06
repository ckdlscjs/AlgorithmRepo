//https://school.programmers.co.kr/learn/courses/30/lessons/135808
#include <bits/stdc++.h>
using namespace std;

int solution(int k, int m, vector<int> score) 
{
    int answer = 0;
    std::sort(score.begin(), score.end(), std::greater<>());
    for(int i = 1; i * m <= score.size(); i++)
    {
        answer += score[i*m-1] * m;
    }
    return answer;
}