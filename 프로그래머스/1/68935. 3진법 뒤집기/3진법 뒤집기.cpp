//https://school.programmers.co.kr/learn/courses/30/lessons/68935
#include <bits/stdc++.h>
using namespace std;

int solution(int n) 
{
    int answer = 0;
    std::string str;
    while(n)
    {
        str += n % 3;
        n /= 3;
    }
    int three = 1;
    for(auto iter = str.rbegin(); iter != str.rend(); iter++)
    {
        answer += *iter * three;
        three *= 3;
    }
    return answer;
}