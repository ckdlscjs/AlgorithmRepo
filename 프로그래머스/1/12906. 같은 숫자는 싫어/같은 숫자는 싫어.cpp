//https://school.programmers.co.kr/learn/courses/30/lessons/12906
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> arr) 
{
    std::vector<int> answer;
    int input = -1;
    for(const auto& iter : arr)
        if(iter != input)
            input = iter, answer.push_back(input);
    return answer;
}