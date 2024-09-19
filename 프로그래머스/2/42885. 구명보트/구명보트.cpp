#include <bits/stdc++.h>
using namespace std;
bool chk[50005];
int solution(vector<int> people, int limit) 
{
    std::sort(people.begin(), people.end(), std::less<>());
    int answer = 0;
    int cur = limit;
    int j = people.size()-1;
    for(int i = 0; i < people.size(); i++)
    {
        if(chk[i])
            continue;
        cur -= people[i];
        chk[i] = true;
        for(j; j > i; j--)
        {
            if(chk[j])
                continue;
            if(cur >= people[j])
            {
                chk[j--] = true;
                break;
            }
        }
        cur = limit;
        answer++;
    }
    
    
    return answer;
}