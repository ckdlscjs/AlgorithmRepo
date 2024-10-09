//https://school.programmers.co.kr/learn/courses/30/lessons/81301
#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, int> nums;
int solution(string s) 
{
    nums["zero"] = 0; 
    nums["one"] = 1; 
    nums["two"] = 2; 
    nums["three"] = 3; 
    nums["four"] = 4; 
    nums["five"] = 5; 
    nums["six"] = 6;
    nums["seven"] = 7; 
    nums["eight"] = 8; 
    nums["nine"] = 9;
    int answer = 0;
    std::string temp;
    for(const auto& iter : s)
    {
        if('0' <= iter && iter <= '9')
        {
            answer = answer*10 + iter-'0';
        } 
        else
        {
            temp += iter;
            if(nums.find(temp) == nums.end())
                continue;
            answer = answer * 10 + nums[temp];
            temp.clear();
        }
    }
    return answer;
}