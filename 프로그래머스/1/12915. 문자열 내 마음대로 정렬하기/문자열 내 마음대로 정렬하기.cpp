//https://school.programmers.co.kr/learn/courses/30/lessons/12915
#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> strings, int n) 
{
    std::sort(strings.begin(), strings.end(), [=](const std::string& a, const std::string& b){
        return a[n] == b[n] ? a < b : a[n] < b[n];
    });
    return strings;
}