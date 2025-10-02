#include <bits/stdc++.h>
using namespace std;

int solution(int n) 
{
    int answer = 0;
    int l = 1, r = 1, sum = 1;
    while(l <= r && r <= n)
    {
        if(sum == n)
        {
            //std::cout << l << ' ' << r << '\n';
            answer++;
            r++;
            sum += r;
        }
        else if(sum > n)
        {
            sum -= l;
            l++;
        }
        else
        {
            r++;
            sum += r;
        }
    }
    return answer;
}