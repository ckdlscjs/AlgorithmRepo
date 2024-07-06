#include <bits/stdc++.h>
using namespace std;
//실패율 = 도전자수/넘긴사람수+도전자수
//result = 실패율높은 스테이지순 내림차순
//실패율이 같은 스테이지가 있다면 작은번호의스테이지가 먼저오며 스테이지에도달한유저가없다면 실패율은0
const int MaxN = 505;
int player_challenge[MaxN];
int player_clear[MaxN];
bool compare(const std::pair<double, int>& a, const std::pair<double, int>& b)
{
    return std::abs(a.first - b.first) == 0.0f ? a.second < b.second : a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) 
{
    for(int i = 0; i < stages.size(); i++)
    {
        for(int j = 1; j < stages[i]; j++)
            player_clear[j]++;
        player_challenge[stages[i]]++;
    }
   
    std::vector<std::pair<double, int>> result;
    for(int i = 1; i <= N; i++)
    {
        std::pair<double, int> p;
        p.second = i;
        if(!player_challenge[i] || !(player_challenge[i] + player_clear[i]))
            p.first = 0.0f;
        else
            p.first = player_challenge[i] / (double)(player_challenge[i] + player_clear[i]);
        result.push_back(p);
    }
    std::sort(result.begin(), result.end(), compare);
    std::vector<int> answer;
    for(const auto& iter : result)
        answer.push_back(iter.second);
    return answer;
}