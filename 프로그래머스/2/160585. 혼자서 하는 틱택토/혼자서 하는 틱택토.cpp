#include <bits/stdc++.h>
using namespace std;
std::string ans;
bool Check(char ch)
{
    if(ans[0] == ch && ans[1] == ch && ans[2] == ch) return true;
    if(ans[3] == ch && ans[4] == ch && ans[5] == ch) return true;
    if(ans[6] == ch && ans[7] == ch && ans[8] == ch) return true;
    if(ans[0] == ch && ans[3] == ch && ans[6] == ch) return true;
    if(ans[1] == ch && ans[4] == ch && ans[7] == ch) return true;
    if(ans[2] == ch && ans[5] == ch && ans[8] == ch) return true;
    if(ans[0] == ch && ans[4] == ch && ans[8] == ch) return true;
    if(ans[6] == ch && ans[4] == ch && ans[2] == ch) return true;
    return false;
}
int solution(vector<string> board) 
{
    int Ocnt = 0, Xcnt = 0;
    for(const auto& iter : board)
    {
        for(const auto& ch : iter)
        {
            if(ch == 'O') Ocnt++;
            if(ch == 'X') Xcnt++;
        }
        ans += iter;
    }
    bool WinO = Check('O');
    bool WinX = Check('X');
    if(Ocnt < Xcnt || std::abs(Ocnt - Xcnt) >= 2) return false;
    if(WinO && WinX) return false;
    if(WinO && Ocnt == Xcnt) return false;
    if(WinX && Ocnt > Xcnt) return false;
    return true;
}