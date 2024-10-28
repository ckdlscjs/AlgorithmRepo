//https://school.programmers.co.kr/learn/courses/30/lessons/12901
#include <bits/stdc++.h>
using namespace std;

string solution(int a, int b) 
{
    std::string weeks[] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = 0;
    for(int i = 1; i < a; i++) sum += month[i-1];
    sum += b - 1;
    return weeks[sum%7];
}