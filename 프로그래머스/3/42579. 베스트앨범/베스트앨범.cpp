#include <bits/stdc++.h>
using namespace std;
/*
1.장르의전체재생횟수
2.해당장르내의 노래의 재생수
3.특정노래들의 재생수가 같다면 idx가 빠른순대로
*/
struct Song
{   
    int play = 0;
    int idx = 0;
    std::string genre = "";
};
//장르의 우선순위큐의 비교를 위한 함수(pq용)
struct Compare
{
    bool operator()(const Song a, const Song b)
    {
        return a.play == b.play ? a.idx > a.idx : a.play < b.play;
    }
};

std::unordered_map<std::string, int> counts; //장르의 전체재생횟수
std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::less<std::pair<int, std::string>>> charts;//전체재생횟수를 카운트하기위한 우선순위큐
std::unordered_map<std::string, std::priority_queue<Song, std::vector<Song>, Compare>> datas; //장르의 우선순위큐가 들어간 컨테이너
vector<int> solution(vector<string> genres, vector<int> plays) 
{
    for(int i = 0; i < genres.size(); i++)
    {
        counts[genres[i]] += plays[i];
        Song song;
        song.play = plays[i];
        song.idx = i;
        song.genre = genres[i];
        if(datas.find(genres[i]) == datas.end())
        {
            std::priority_queue<Song, std::vector<Song>, Compare> pq;
            pq.push(song);
            datas[genres[i]] = pq;
        }
        else
        {
            datas[genres[i]].push(song);
        }
    }
    for(const auto& iter : counts)
    {
        charts.push({iter.second, iter.first});
    }
    vector<int> answer;
    while(charts.size())
    {
        std::string chart = charts.top().second;
        charts.pop();
        int cnt = 0;
        while(datas[chart].size() && cnt < 2)
        {
            Song song = datas[chart].top();
            datas[chart].pop();
            answer.push_back(song.idx);
            cnt++;
        }
    }
    
    return answer;
}