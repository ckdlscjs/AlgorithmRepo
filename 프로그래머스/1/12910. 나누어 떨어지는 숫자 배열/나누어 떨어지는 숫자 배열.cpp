//https://school.programmers.co.kr/learn/courses/30/lessons/12910
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr, int divisor)
{
    std::set<int> chks;
    for(const auto& iter : arr)
        if(iter%divisor == 0)
            chks.insert(iter);
    vector<int> answer(chks.begin(), chks.end());
    if(answer.empty())
        answer.push_back(-1);
    return answer;
}