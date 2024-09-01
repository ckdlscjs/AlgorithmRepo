#include <bits/stdc++.h>
using namespace std;
std::map<int, int> lasts;
std::map<int, int> cnts;
int solution(vector<int> topping) 
{
    int answer = 0;
    for(const auto& iter : topping)
        lasts[iter]++;
    int zero_cnt = 0;
    for(int i = 0;i < topping.size()-1; i++)
    {
        cnts[topping[i]]++;
        lasts[topping[i]]--;
        if(lasts[topping[i]] <= 0)
            zero_cnt++;
        if(cnts.size() == lasts.size() - zero_cnt)
            answer++;
    }
    return answer;
}