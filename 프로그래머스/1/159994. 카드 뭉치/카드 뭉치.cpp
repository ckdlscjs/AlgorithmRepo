#include <bits/stdc++.h>
using namespace std;
int lidx, ridx;
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    bool chk = true;
    for(const auto& iter : goal)
    {
        if(iter == cards1[lidx])
            lidx++;
        else if(iter == cards2[ridx])
            ridx++;
        else
        {
            chk = false;
            break;
        }
    }
    return chk ? "Yes" : "No";
}