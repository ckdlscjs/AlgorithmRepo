//https://school.programmers.co.kr/learn/courses/30/lessons/250137
#include <bits/stdc++.h>
using namespace std;
int attack[1005];
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) 
{
    for(const auto& iter : attacks)
        attack[iter[0]] = iter[1];
    int cur = health;
    int cont_cnt = 0;
    for(int t = 1; t <= attacks[attacks.size()-1][0]; t++)
    {
        if(attack[t])
        {
            cont_cnt = 0;
            cur -= attack[t];
            if(cur <= 0)
                break;
            continue;
        }
        cur = std::min(cur + bandage[1], health);
        cont_cnt++;
        cur = std::min(cur + (cont_cnt / bandage[0] ? bandage[2] : 0), health);
        cont_cnt %= bandage[0];
        //std::cout << t << ' ' << cur << ' ' <<cont_cnt << ' ' <<attack[t] <<'\n';
    }
    return cur > 0? cur : -1;
}