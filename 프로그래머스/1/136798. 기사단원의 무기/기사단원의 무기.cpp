//https://school.programmers.co.kr/learn/courses/30/lessons/136798
#include <bits/stdc++.h>
using namespace std;
int solution(int number, int limit, int power) 
{
    int answer = 0;
    while(number)
    {
        std::unordered_set<int> divisors;
        for(int i = 1; i <= std::sqrt(number); i++)
        {
            if(number % i == 0)
            {
                divisors.insert(number / i);
                divisors.insert(i);
            }
        }
        answer += divisors.size() <= limit ? divisors.size() : power;
        number--;
    }
    return answer;
}