#include <bits/stdc++.h>
using namespace std;
std::map<std::string, std::vector<int>> cars;
vector<int> solution(vector<int> fees, vector<string> records) 
{
    for(const auto& str : records)
    {
        int time = ((str[0]-'0')*10 + (str[1]-'0'))*60;
        time += (str[3]-'0')*10 + (str[4]-'0');
        std::string num = str.substr(6, 4);
        //std::string inout = str.substr(11);
        //std::cout << time << ' ' << num << ' ' << inout << '\n';
        cars[num].push_back(time);
    }
    vector<int> answer;
    for(auto car : cars)
    {
        if(car.second.size() % 2)
            car.second.push_back(23*60+59);
        int idx = car.second.size()-1;
        int sum = 0;
        while(idx > 0)
        {
            sum += car.second[idx] - car.second[idx-1];
            idx-=2;
        }
        answer.push_back(fees[1] + (sum <= fees[0] ? 0 : std::ceil((sum-fees[0]) / (float)fees[2])) * fees[3]);
    }
    
    return answer;
}