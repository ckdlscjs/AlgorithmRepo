//https://school.programmers.co.kr/learn/courses/30/lessons/77884
#include <bits/stdc++.h>
using namespace std;
std::unordered_map<int, std::set<int>> nums;
int solution(int left, int right) 
{
    for(int i = 1; i <= 1000; i++)
    {
        for(int j = 1; j <= std::sqrt(i); j++)
        {
            if(i%j == 0)
            {
                nums[i].insert(i/j);
                nums[i].insert(j);
            }
        }
    }
    int answer = 0;
    for(left; left <= right; left++)
        answer += nums[left].size() % 2 ? -1*left : left;
    return answer;
}