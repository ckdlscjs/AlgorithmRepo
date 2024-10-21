//https://school.programmers.co.kr/learn/courses/30/lessons/12930
#include <bits/stdc++.h>
using namespace std;
string solution(string s) 
{
    int idx = 0;
    for(char& ch : s)
    {
        if(ch == ' ')
        {
            idx = 0;
            continue;
        }
        if(idx % 2 == 0 && 'a' <= ch)
            ch -= 32;
        else if(idx % 2 != 0 && ch <= 'Z')
            ch += 32;
        idx++;
    }
    return s;
}