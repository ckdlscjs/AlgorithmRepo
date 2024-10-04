#include <bits/stdc++.h>
using namespace std;
int solution(string s) 
{
    char ch = s[0];
    int cnt_f = 0;
    int cnt_other = 0;
    int answer = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(ch == s[i])
            cnt_f++;
        else
            cnt_other++;
        if(cnt_f == cnt_other)
        {
            //std::cout << i <<'\n';
            answer++;
            cnt_f = 0;
            cnt_other = 0;
            ch = s[i+1];
        }
    }
    return cnt_f != 0 ? answer+1 : answer;
}