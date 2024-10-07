//https://school.programmers.co.kr/learn/courses/30/lessons/132267
#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b, int n) 
{
    int answer = 0;
    while(n >= a)
    {
        int calc = n / a;
        answer += calc * b;
        n = (n-calc*a) + calc*b;
    }
    return answer;
}