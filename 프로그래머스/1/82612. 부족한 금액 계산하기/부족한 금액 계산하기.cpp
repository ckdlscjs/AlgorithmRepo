//https://school.programmers.co.kr/learn/courses/30/lessons/82612
#include <bits/stdc++.h>
using namespace std;
long long solution(int price, int money, int count)
{
    long long answer = 0;
    for(int i = 1; i <= count; i++)
        answer += price * i;
    return answer - money >= 0 ? answer - money : 0;
}