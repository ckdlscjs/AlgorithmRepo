//https://school.programmers.co.kr/learn/courses/30/lessons/12901
#include <bits/stdc++.h>
using namespace std;
std::unordered_map<int, int> month;
std::string weeks[7];
string solution(int a, int b) 
{
    int sum = 0;
    weeks[0] = "FRI"; weeks[1] = "SAT"; weeks[2] = "SUN"; weeks[3] = "MON"; weeks[4] = "TUE"; weeks[5] = "WED"; weeks[6] = "THU";
    month[1] = 31; month[2] = 29; month[3] = 31; month[4] = 30; month[5] = 31; month[6] = 30; 
    month[7] = 31; month[8] = 31; month[9] = 30; month[10] = 31; month[11] = 30; month[12] = 31;
    for(int i = 1; i < a; i++)
        sum += month[i];
    sum += b - 1;
    //std::cout << sum;
    return weeks[sum%7];
}