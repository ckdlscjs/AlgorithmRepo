#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) 
{
    std::sort(people.begin(), people.end());
    int l = 0, r = people.size()-1;
    int answer = 0;
    while(l <= r)
    {
        if(people[l] + people[r] > limit)
        {
            answer++;
            r--;
        }
        else
        {
            answer++;
            l++;
            r--;
        }
    }
    return answer;
}