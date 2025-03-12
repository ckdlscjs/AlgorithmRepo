#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) 
{
    int answer = 0;
    int _size = schedules.size();
    for(int i = 0; i < _size; i++)
    {
        int cnt = 0;
        int limit = (schedules[i]/100*60) + (schedules[i]%100) + 10;
        int start = startday;
        for(int j = 0; j < timelogs[i].size(); j++, start++)
        {
            if(start >= 8) start -= 7;
            if(start >= 6) continue;
            int enter = (timelogs[i][j]/100*60) + (timelogs[i][j]%100);
            if(enter <= limit) cnt++;
        }
        if(cnt >= 5) answer++;
    }
    return answer;
}