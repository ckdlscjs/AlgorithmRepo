//https://school.programmers.co.kr/learn/courses/30/lessons/340199
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) 
{
    int answer = 0;
    while(std::min(wallet[0], wallet[1]) < std::min(bill[0], bill[1]) || std::max(wallet[0], wallet[1]) < std::max(bill[0], bill[1]))
    {
        if(bill[0] > bill[1])
            bill[0] /= 2;
        else
            bill[1] /= 2;
        answer++;
    }
    
    return answer;
}