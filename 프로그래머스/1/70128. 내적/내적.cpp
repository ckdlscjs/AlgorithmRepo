//https://school.programmers.co.kr/learn/courses/30/lessons/70128
#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> a, vector<int> b) 
{
    int answer = 0;
    for(int i = 0; i < a.size(); i++)
        answer += a[i] * b[i];
    return answer;
}