#include <bits/stdc++.h>
std::vector<int> an[3] = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
int ans[3], maxcnt;
using namespace std;

vector<int> solution(vector<int> answers) 
{
    for(int i = 0; i < answers.size(); i++)
    {
        ans[0] += answers[i] == an[0][i%an[0].size()];
        ans[1] += answers[i] == an[1][i%an[1].size()];
        ans[2] += answers[i] == an[2][i%an[2].size()];
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