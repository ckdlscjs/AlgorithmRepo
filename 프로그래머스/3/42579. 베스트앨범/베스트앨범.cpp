//https://school.programmers.co.kr/learn/courses/30/lessons/42579
#include <bits/stdc++.h>
using namespace std;
std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::less<std::pair<int, std::string>>>pq;
std::unordered_map<std::string, int> cnts;
struct compare
{
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b)
    {
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    }
};
std::unordered_map<std::string, std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, compare>> songs;
vector<int> solution(vector<string> genres, vector<int> plays) 
{
    
    for(int i = 0; i < genres.size(); i++)
    {
        cnts[genres[i]] += plays[i];
        songs[genres[i]].push({plays[i], i});
    }
    for(const auto& iter : cnts)
        pq.push({iter.second, iter.first});
    vector<int> answer;
    while(pq.size())
    {
        std::string genre = pq.top().second;
        pq.pop();
        int cnt = 0;
        while(songs[genre].size() && cnt < 2)
        {
            answer.push_back(songs[genre].top().second);
            songs[genre].pop();
            cnt++;
        }
    }
    return answer;
}