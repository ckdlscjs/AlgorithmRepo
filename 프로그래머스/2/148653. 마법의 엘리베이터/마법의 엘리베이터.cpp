#include <bits/stdc++.h>
using namespace std;

int solution(int storey) 
{
    int answer = 0;
    while(storey)
    {
        int cur = storey % 10;
        storey /= 10;
        if(cur == 5)
        {
            answer += 5;
            if(storey % 10 >= 5) storey += 1;
        }
        else if(cur < 5)
        {
            answer += cur;
        }
        else if(cur > 5)
        {
            answer += 10 - cur;
            storey += 1;
        }
        
        //std::cout << storey << '\n';
    }
    return answer;
}