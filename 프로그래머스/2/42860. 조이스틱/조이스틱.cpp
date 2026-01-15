#include <bits/stdc++.h>
using namespace std;
int solution(string name) 
{
    int answer = name.size()-1;
    for(int i = 0; i < name.size(); i++)
    {
        int cursor = i+1;
        while(cursor < name.size() && name[cursor] == 'A') cursor++;
        //...i AAAA cursor... 
        answer = std::min(answer, (int)(i*2 + name.size() - cursor)); //left*2, left
        answer = std::min(answer, (int)(i + (name.size() - cursor) * 2)); //left, right*2
    }
    
    for(const auto& iter : name)
    {
        int diff = iter - 'A';
        answer += std::min(diff, 26-diff);
    }
    return answer;
}