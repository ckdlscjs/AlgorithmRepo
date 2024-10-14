//https://school.programmers.co.kr/learn/courses/30/lessons/68935
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> numbers) 
{
    std::set<int> chks;
    for(int i = 0; i < numbers.size(); i++)
        for(int j = i+1; j < numbers.size(); j++)
            chks.insert(numbers[i] + numbers[j]);
    return std::vector<int>(chks.begin(), chks.end());
}