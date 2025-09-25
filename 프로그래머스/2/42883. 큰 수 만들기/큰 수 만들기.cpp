#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) 
{
    std::string answer;
    int idx = -1;
    for(int i = 0; i < number.size() - k; i++)
    {
        char ch = 0;
        for(int j = idx + 1; j <= i + k; j++)
        {
            if(number[j] > ch)
            {
                ch = number[j];
                idx = j;
            }
        }
        answer += ch;
    }
        
    return answer;
}