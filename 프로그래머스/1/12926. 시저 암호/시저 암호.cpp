//https://school.programmers.co.kr/learn/courses/30/lessons/12926
#include <bits/stdc++.h>
using namespace std;

string solution(string s, int n) 
{
    for(char& ch: s)
        if(ch != ' ')
            ch = ('A' <= ch && ch <= 'Z') ? ((ch+n)-'A')%26 + 'A' : ((ch+n)-'a')%26 + 'a';
    return s;
}