#include <bits/stdc++.h>

using namespace std;

int solution(string s) 
{
    int answer = 0;
    char x;
    int count_x = 0;
    int count_other = 0;
    for(const auto& ch : s)
    {
        if(!count_x)
        {
            count_x = 1;
            x = ch;
        }
        else
        {
            if(ch == x)
                count_x++;
            else
                count_other++;
            if(count_x == count_other)
            {
                answer++;
                count_x = 0;
                count_other = 0;
            }
        }
    }
    return count_x ? answer+1 : answer;
}