#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    std::vector<int> answer;
    int y = 3;
    while(!answer.size())
    {
        int b = 3;
        while(b * y < brown + yellow)
        {
            b++;
        }
        if(b * y == brown + yellow)
        {
            int cnt_b = b * 2 + (y-2) * 2;
            int cnt_y = brown + yellow - cnt_b;
            if(cnt_b == brown && cnt_y == yellow)
            {
                answer.push_back(b);
                answer.push_back(y);
            }  
        }
        y++;
    }
    return answer;
}