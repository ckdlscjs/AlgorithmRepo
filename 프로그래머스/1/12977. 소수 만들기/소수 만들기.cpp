//https://school.programmers.co.kr/learn/courses/30/lessons/12977
#include <bits/stdc++.h>
using namespace std;
bool NotPrime[3000];
int solution(vector<int> nums) 
{
    for(int i = 2; i <= std::sqrt(3'000); i++)
    {
        if(NotPrime[i])
            continue;
        for(int j = 2; i * j <= 3000; j++)
            NotPrime[i*j] = true;
    }
    int answer = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            for(int k = j + 1; k < nums.size(); k++)
            {
                if(!NotPrime[nums[i] + nums[j] + nums[k]])
                    answer++;
            }
        }
    }
    return answer;
}