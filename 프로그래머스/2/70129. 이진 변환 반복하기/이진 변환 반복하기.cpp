#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) 
{
    int count = 0;
    int count_0 = 0;
    while(s != "1")
    {
        count++;
        int nxt = 0;
        std::string nxt_s;
        for(const auto& ch : s)
        {
            if(ch == '0') count_0++;
            else nxt++;
        }
        while(nxt)
        {
            nxt_s += std::to_string(nxt%2);
            nxt /= 2;
        }
        s = nxt_s;
    }
    return {count, count_0};
}