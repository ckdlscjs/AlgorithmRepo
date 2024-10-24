//https://school.programmers.co.kr/learn/courses/30/lessons/131701
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> elements) 
{
    int length = elements.size();
    for(int i = 0; i < length; i++) 
        elements.push_back(elements[i]);
    std::unordered_set<int> chks;
    for(int len = 0; len < length; len++)
    {
        for(int i = 0; i < length; i++)
        {
            int sum = 0;
            for(int j = 0; j <= len; j++)
                sum += elements[i+j];
            chks.insert(sum);
        }
    }
    return chks.size();
}