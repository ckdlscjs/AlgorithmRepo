//https://school.programmers.co.kr/learn/courses/30/lessons/12985
#include <bits/stdc++.h>
using namespace std;
int solution(int n, int a, int b)
{
    int answer = 0;
    while(a != b)
    {
        answer++;
        a = (a+1) >> 1;
        b = (b+1) >> 1;
    }
    return answer;
}