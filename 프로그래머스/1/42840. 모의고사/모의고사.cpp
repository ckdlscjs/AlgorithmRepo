#include <bits/stdc++.h>
std::vector<int> an[3] = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
int ans[3], maxcnt;
using namespace std;

vector<int> solution(vector<int> answers) 
{
    for(int i = 0; i < answers.size(); i++)
    {
        for(int j = 0; j < 3; j++)
            ans[j] += answers[i] == an[j][i%an[j].size()]; 
    }
    maxcnt = std::max({ans[0], ans[1], ans[2]});
    std::vector<int> answer;
    for(int i = 0; i < 3; i++)
    {
        if(maxcnt == ans[i])
            answer.push_back(i+1);
    }
    return answer;
}