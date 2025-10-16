/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
std::string str;
int mask = (1 << ('A' - 'A')) | (1 << ('E' - 'A')) | (1 << ('I' - 'A')) | (1 << ('O' - 'A')) | (1 << ('U' - 'A'));
bool isAEIOU(char ch)
{
    return mask & (1 << (ch-'A'));
}
long long Check(int idx, int cntC, int cntV, bool hasL)
{
    if(idx >= str.size()) return hasL;
    long long ret = 0;
    if(str[idx] == '_')
    {
        if(cntC >= 2)
        {
            ret += 5 * Check(idx+1, 0, cntV+1, hasL);
        }
        else if(cntV >= 2)
        {
            ret += 20 * Check(idx+1, cntC+1, 0, hasL);
            ret += Check(idx+1, cntC+1, 0, true);
        }
        else
        {
            ret += 5 * Check(idx+1, 0, cntV+1, hasL);
            ret += 20 * Check(idx+1, cntC+1, 0, hasL);
            ret += 1 * Check(idx+1, cntC+1, 0, true);
        }
    }
    else if(isAEIOU(str[idx]))
    {
        if(cntV >= 2) return 0;
        ret += Check(idx+1, 0, cntV+1, hasL);
    }
    else
    {
        if(cntC >= 2) return 0;
        if(str[idx] == 'L')
            ret += Check(idx+1, cntC+1, 0, true);
        else
            ret += Check(idx+1, cntC+1, 0, hasL);
    }
    return ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> str;
    std::cout << Check(0, 0, 0, false);
    return 0;
}
