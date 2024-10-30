//https://school.programmers.co.kr/learn/courses/30/lessons/17687
#include <bits/stdc++.h>
using namespace std;
string solution(int n, int t, int m, int p) 
{
    char lists[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string answer = "";
    int start = 0;
    int turn = 0;
    int numidx = 0;
    std::string num = "";
    
    while(answer.size() < t)
    {
        if(num.empty())
        {
            numidx = 0;
            int cur = start;
            while(cur)
            {
                num += lists[cur%n];
                cur /= n;
            }
            if(num.empty())
                num += lists[0];
            std::reverse(num.begin(), num.end());
        }
        if((turn%m) + 1 == p)
            answer += num[numidx];
        turn++;
        numidx++;
        if(numidx >= num.size())
        {
            num.clear();
            start++;
        }
    }
    
    return answer;
}