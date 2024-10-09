//https://school.programmers.co.kr/learn/courses/30/lessons/86051
#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> numbers) 
{
    int answer = 45;
    for(const auto& iter : numbers)
        answer -= iter;
    return answer;
}