#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) 
{
    int idx = -1;
    string answer = "";
    for(int i = 0; i < number.size() - k; i++)
    {
        char ch = 0;
        for(int j = idx+1; j <= k+i; j++)
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