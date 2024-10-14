//https://school.programmers.co.kr/learn/courses/30/lessons/67256
#include <bits/stdc++.h>
using namespace std;
std::unordered_map<int, std::pair<int, int>> btns;
string solution(vector<int> numbers, string hand) 
{
    int idx = 1;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            btns[idx++] = {i, j};
    btns[10] = {3, 0};
    btns[0] = {3, 1};
    btns[11] = {3, 2};
            
    std::pair<int, int> l = btns[10], r = btns[11];
    string answer = "";
    for(const auto& iter : numbers)
    {
        if(iter == 1 || iter == 4 || iter == 7)
        {
            l = btns[iter];
            answer += 'L';
        }
        else if(iter == 3 || iter == 6 || iter == 9)
        {
            r = btns[iter];
            answer += 'R';
        }
        else
        {
            int dist_l = std::abs(btns[iter].first - l.first) + std::abs(btns[iter].second - l.second);
            int dist_r = std::abs(btns[iter].first - r.first) + std::abs(btns[iter].second - r.second);
            if(dist_l == dist_r)
            {
                //std::cout <<iter<<"->"<< dist_l <<":"<<dist_r <<'\n';
                answer += (hand[0] - 'a' + 'A');
                if(hand[0] == 'l')
                    l = btns[iter];
                else
                    r = btns[iter];
            }
            else if(dist_l < dist_r)
            {
                answer += 'L';
                l = btns[iter];
            }
            else
            {
                answer += 'R';
                r = btns[iter];
            }
        }
    }
    
    return answer;
}