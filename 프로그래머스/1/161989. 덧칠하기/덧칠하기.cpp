//https://school.programmers.co.kr/learn/courses/30/lessons/161989
#include <bits/stdc++.h>
using namespace std;
int solution(int n, int m, vector<int> section) 
{
    int answer = 1;
    int l = section[0];
    int r = l + m - 1;
    for(int i = 1; i < section.size(); i++)
    {
        if(section[i] > r)
        {
            answer++;
            r = std::min(section[i]+m-1, n);
        }
    }
    return answer;
}