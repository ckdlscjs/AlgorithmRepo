//https://school.programmers.co.kr/learn/courses/30/lessons/12935
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> arr) 
{
    arr.erase(std::min_element(arr.begin(), arr.end()));
    if(arr.empty()) arr.push_back(-1);
    return arr;
}