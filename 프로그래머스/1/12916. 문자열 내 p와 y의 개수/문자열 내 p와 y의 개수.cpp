//https://school.programmers.co.kr/learn/courses/30/lessons/12916
#include <bits/stdc++.h>
using namespace std;
bool solution(string s)
{
    int Pp = 0, Yy = 0;
    for(const auto& iter : s)
    {
        if(iter == 'p' || iter == 'P') Pp++;
        if(iter == 'y' || iter == 'Y') Yy++;
    }
    return Pp == Yy ? true : false;
}