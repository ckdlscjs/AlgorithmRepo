//https://school.programmers.co.kr/learn/courses/30/lessons/12947
#include <bits/stdc++.h>
using namespace std;

double solution(vector<int> arr) 
{
    double answer = 0;
    for(const auto& num : arr)
        answer+= num;
    return answer/arr.size();
}