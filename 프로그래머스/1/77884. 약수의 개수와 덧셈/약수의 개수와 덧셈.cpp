#include <bits/stdc++.h>

using namespace std;

int solution(int left, int right) 
{
    int answer = 0;
    for(left; left <= right; left++)
    {
        std::set<int> temp;
        for(int i = 1; i <= std::sqrt(left); i++)
        {   
            if(left % i == 0)
            {
                temp.insert(i);
                temp.insert(left/i);
            }
        }
        std::cout << temp.size() <<'\n';
        answer += temp.size() % 2 == 0 ? left : -left;
    }
    return answer;
}