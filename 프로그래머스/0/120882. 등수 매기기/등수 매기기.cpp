#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<vector<int>> score) {
    std::priority_queue<std::pair<float, int>, std::vector<std::pair<float,int>>, std::less<std::pair<float,int>>> pq;
    for(int i = 0; i < score.size(); i++)
    {
        pq.push({(score[i][0] + score[i][1])/2.0f, i});
    }
    int rank = 1;
    int count = 0;
    vector<int> answer;
    answer.resize(score.size());
    while(pq.size())
    {
        auto iter = pq.top();
        pq.pop();
        answer[iter.second] = rank;
        count++;
        if(pq.size() && iter.first != pq.top().first)
        {
            rank += count;
            count = 0;
        }
    }
    
    return answer;
}