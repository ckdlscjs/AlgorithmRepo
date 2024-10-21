//https://school.programmers.co.kr/learn/courses/30/lessons/12932
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(long long n) 
{
    vector<int> answer;
    while(n)
    {
        answer.push_back(n%10);
        n /= 10;
    }
    return answer;
}