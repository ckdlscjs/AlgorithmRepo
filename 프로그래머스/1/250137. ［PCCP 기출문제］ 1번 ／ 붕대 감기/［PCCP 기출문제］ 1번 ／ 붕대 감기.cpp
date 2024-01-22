#include <bits/stdc++.h>

using namespace std;
/*
bandage -> t, x, y 1초마다 x회복, t초성공시 y추가회복
t도중 피격시 취소됨, t가초기화됨

피격시 피해량만큼체력이감소됨, 0이하는 사망

health는 최대체력

attacks는 공격시간, 피해량

모든공격이끝나고 남은체력을 return, 사망시 -1
*/
int at[1010];
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) 
{
    int t_last = 0;
    for(const auto& iter : attacks)
    {
        at[iter[0]] = iter[1];
        t_last = iter[0];
    }
        
    int cur_health = health;
    int t = 0;
    int t_ing = 0;
    while(t <= t_last && cur_health > 0)
    {
        if(at[t])
        {
            cur_health -= at[t];
            t_ing = 0;
        }   
        else
        {   if(t_ing)
                cur_health = std::min(cur_health + bandage[1], health);
            if(t_ing >= bandage[0])
            {
                t_ing = 0;
                cur_health = std::min(cur_health + bandage[2], health);
            }
            
        }
        std::cout << t << ' ' << cur_health << ' ' << t_ing << ' '<< (at[t] ? 'O' : 'X') << '\n';
        t_ing++;
        t++;
    }
    return cur_health > 0 ? cur_health : -1;
}