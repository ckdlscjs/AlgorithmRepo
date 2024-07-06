#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> answers) 
{
    std::vector<std::vector<int>> player;
    std::vector<int> p1 = {1,2,3,4,5};
    std::vector<int> p2 = {2,1,2,3,2,4,2,5};
    std::vector<int> p3 = {3,3,1,1,2,2,4,4,5,5};
    player.push_back(p1);
    player.push_back(p2);
    player.push_back(p3);
    vector<int> score;
    score.push_back(0);
    score.push_back(0);
    score.push_back(0);
    int maximum = 0;
    for(int i = 0; i < answers.size(); i++)
    {
        if(player[0][i % player[0].size()] == answers[i])
            score[0]++;
        maximum = std::max(maximum, score[0]);
        if(player[1][i % player[1].size()] == answers[i])
            score[1]++;
        maximum = std::max(maximum, score[1]);
        if(player[2][i % player[2].size()] == answers[i])
            score[2]++; 
        maximum = std::max(maximum, score[2]);
        
    }
    std::vector<int> answer;
    for(int i = 0; i < score.size(); i++)
        if(score[i] == maximum)
            answer.push_back(i+1);
    return answer;
}